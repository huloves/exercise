#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct tmp2 //重写仿函数
{
    bool operator() (struct ListNode* a, struct ListNode* b) 
    {
        return a->val > b->val;
    }
};
// bool operator() (struct ListNode *a, struct ListNode *b);

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        ListNode *vhead = new ListNode(-1);
        ListNode *current = vhead;
        priority_queue<ListNode*, vector<ListNode*>, tmp2> pq;
        for(auto temp : lists) {
            if(temp != nullptr) {
                pq.push(temp);
            }
        }
        while(!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            if(node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return vhead->next;
    }
};
