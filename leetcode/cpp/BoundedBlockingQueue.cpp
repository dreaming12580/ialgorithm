#include <bits/stdc++.h>

using namespace std;


class BoundedBlockingQueue {
private:
  pthread_mutex_t mutex;
  pthread_cond_t rcond;
  pthread_cond_t wcond;
  int max_size;
  queue<int> data;
public:
  BoundedBlockingQueue(int capacity) {
    max_size = capacity;
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&rcond, 0);
    pthread_cond_init(&wcond, 0);
  }

  void enqueue(int element) {
    pthread_mutex_lock(&mutex);
    while (data.size() == max_size) {
      // 处理条件变量 wcond 惊群问题
      pthread_cond_wait(&wcond, &mutex);
    }
    data.push(element);
    pthread_cond_signal(&rcond);
    pthread_mutex_unlock(&mutex);
  }

  int dequeue() {
    pthread_mutex_lock(&mutex);
    while (!data.size()) {
      // 处理条件变量 rcond 惊群问题
      pthread_cond_wait(&rcond, &mutex);
    }
    int val = data.front();
    data.pop();
    pthread_cond_signal(&wcond);
    pthread_mutex_unlock(&mutex);
    return val;
  }

  int size() {
    return data.size();
  }

};















