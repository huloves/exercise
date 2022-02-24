#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode() : val(0), next(nullptr) { }
	ListNode(int val) : val(val), next(nullptr) { }
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* find_x(ListNode* head, int x) {
        ListNode *cur = head;
        for(int i = 0; i < x; i++) {
            cur = cur->next;
        }
        return cur;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *Node_m = find_x(head, m);
        ListNode *pre_m = find_x(head, m-1);
        ListNode *Node_n = find_x(head, n);
        ListNode *n_next = Node_n->next;
        pre_m->next = reverseList(Node_m, n_next);
        ListNode *cur = head;
        while(cur != Node_m) {
            cur = cur->next;
        }
        cur->next = n_next;
        return head;
    }
    ListNode* reverseList(ListNode* node_m, ListNode* node_n) {
        ListNode *cur = node_m;
        ListNode *mid = cur->next;
        ListNode *tail;
        while(mid != node_n) {
            tail = mid->next;
            mid->next = cur;
            cur = mid;
            mid = tail;
        }
        return cur;
    }
	void print_list(ListNode* head) {
		ListNode* current = head->next;
		while(current != nullptr) {
			cout << current->val << endl;;
			current = current->next;
		}
	}
};

int main()
{
	cout << "asdf" << endl;
	Solution solution;
	ListNode* head = new ListNode();
	ListNode* current = head;
	for(int i = 0; i < 2; i++) {
		ListNode *temp = new ListNode();
		cin >> temp->val;
		current->next = temp;
		current = temp;
	}
	current = head->next;
	while(current != nullptr) {
		cout << current->val << endl;;
		current = current->next;
	}
	// solution.print_list(head);
	head = solution.reverseBetween(head, 1, 2);
	solution.print_list(head);
	return 0;
}
