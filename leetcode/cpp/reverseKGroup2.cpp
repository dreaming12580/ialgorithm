#include <iostream>
#include <tuple>


using namespace std;



struct ListNode {
    ListNode* next;
    int val;

    ListNode(int v) : val(v) {}
};



class Solution {
public:

    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* prev = hair;

        while (head) {
            ListNode* tail = prev;
            // 查看剩余部分长度是否大于等于k 
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* next = tail->next;

            tie(head, tail) = myReverse(head, tail);
            prev->next = head;
            tail->next = next;
            prev = tail;
            head = tail->next;
        }
        return hair->next;
    }






};










