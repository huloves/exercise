#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *vhead = new ListNode(-1);
        vhead->next = head;
        ListNode *fast = vhead;
        ListNode *slow = vhead;
        for(int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        // free(temp);
        delete(temp);
        return vhead->next;
    }
};
