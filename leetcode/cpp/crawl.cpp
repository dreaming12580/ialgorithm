/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BlockingQueue {
public:
  BlockingQueue() : head_(new Node), tail_(head_) {}
  ~BlockingQueue() {delete tail_; }

  void Push(const T& value) {
    lock_guard<mutex> lk(tail_mutex_);
    tail_->value = value;
    PushNewTail();
  }

  T& Push(T&& value) {
    lock_guard<mutex> lk(tail_mutex_);
    tail_->value = move(value);
    PushNewTail();
    return tail_->value;
  }

  bool TryPop(T& value) {
    lock_guard<mutex> lk(head_mutex_);
    if (head_ == GetTail()) {
      return false;
    }
    Node* old_head = head_;
    value = move(old_head->value);
    head_ = old_head->next;
    delete old_head;
    return true;
  }

  T Pop() {
    unique_lock<mutex> lk(head_mutex_);
    cond_var_.wait(lk, [this] { return head_ != GetTail(); });

    Node* old_head = head_;
    T value = move(old_head->value);
    head_ = old_head->next;
    delete old_head;
    return value;
  }

  shared_ptr<T> PopFor(int millisec) {
    unique_lock<mutex> lk(head_mutex_);
    cond_var_.wait_for(lk, std::chrono::milliseconds(millisec),
                          [this] { return head_ != GetTail(); });

    if (head_ == GetTail()) {
      return nullptr;
    }
    Node* old_head = head_;
    shared_ptr<T> value = make_shared<T>(move(old_head->value));
    head_ = old_head->next;
    delete old_head;
    return value;
  }

  bool Empty() {
    unique_lock<mutex> lk(head_mutex_);
    return head_ == GetTail();
  }

private:
  struct Node;

  void PushNewTail() {
    Node* new_tail = new Node;
    tail_->next = new_tail;
    tail_ = new_tail;
    cond_var_.notify_one();
  }

  Node* GetTail() const {
    lock_guard<mutex> lk(tail_mutex_);
    return tail_;
  }

  struct Node {
    T value;
    Node* next;

    Node() {}
    Node(const T& v) : value(v), next(nullptr) {}
    Node(T&& v) : value(move(v)), next(nullptr) {}
  };

  mutex head_mutex_;
  mutable mutex tail_mutex_;
  condition_variable cond_var_;
  Node* head_;
  Node* tail_;
};





class Solution {
private:
  unordered_set<string> url_set_;
  mutex url_set_mutex_;

public:
  vector<string> crawl(string start_url, HtmlParser html_parser) {
    BlockingQueue<string> request_queue;
    string host_name = GetHostName(start_url);
    request_queue.Push(start_url);

    int len = std::thread::hardware_concurrency();
    std::thread* threads[len];
    int running_mask = 0;

    mutex m;
    condition_variable cond;

    for (int i = 0; i < len; ++i) {
      std::thread* t = new std::thread([&, i, this] {
        while (true) {
          unique_lock<mutex> lk(m);
          cond.wait(lk, [&] {
            return !request_queue.Empty() || running_mask == 0;
          });

          if (running_mask == 0 && request_queue.Empty()) {
            return;
          }

          string url = request_queue.Pop();
          running_mask |= (1 << i);
          lk.unlock();

          if (GetHostName(url) == host_name && TryInsertURL(url)) {
            vector<string> urls = html_parser.getUrls(url);
            for (string& sub_url : urls) {
              request_queue.Push(sub_url);
              cond.notify_one();
            }
          }

          lk.lock();
          running_mask &= !(1 << i);
          if (running_mask == 0 && request_queue.Empty()) {
            cond.notify_all();
          }
          lk.unlock();
        }
      });
      threads[i] = t;
    }

    for (int i = 0; i < len; ++i) {
      threads[i]->join();
      delete threads[i];
    }

    vector<string> res;
    for (const string& url : url_set_) {
      res.push_back(url);
    }
    return res;
  }

  string GetHostName(const string& url) {
    string parsed_url = url.substr(7, url.size() - 7);
    int index = parsed_url.find_first_of('/');
    return index > 0 ? parsed_url.substr(0, index) : parsed_url;
  }

  bool TryInsertURL(const string& url) {
    lock_guard<mutex> lk(url_set_mutex_);
    if (url_set_.find(url) != url_set_.end()) {
      return false;
    }
    url_set_.insert(url);
    return true;
  }





};










