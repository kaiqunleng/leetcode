#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
#include<forward_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr) {
			return nullptr;
		}

		ListNode* ptr = head;
		while (ptr->val == val) {
			ptr = ptr->next;
		}
		ListNode*cand = ptr;
		while (cand->next != nullptr) {
			if (cand->next->val == val) {
				cand->next = cand->next->next;
				if (cand->next->val != val) {
					cand = cand->next;
				}
			}
		}
		return ptr;
	}
};
int main(int argc, char *argv[])
{
	ListNode a(2);
	ListNode b(2);
	ListNode c(3);
	a.next = &b;
	b.next = &c;
	Solution d;
	ListNode* e = d.removeElements(&a,2);
	cout << e->val << endl;
	cout << e->next->val;

	return 0;
}



