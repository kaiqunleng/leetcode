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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *A = headA;
		ListNode *B = headB;
		ListNode* ans = headA;
		if (A == nullptr || B == nullptr) {
			return nullptr;
		}
		while (A != nullptr)
		{
			int num = A->val;
			numsa.push_back(num);
			A = A->next;
		}
		while (B != nullptr) {
			int num = B->val;
			numsb.push_back(num);
			B = B->next;
		}
		int sizea = numsa.size() - 1;
		int sizeb = numsb.size() - 1;
		int DIF = sizea + 1;
		int j = 0;
		while (sizea >= 0 && sizeb >= 0) {
			if (numsa[sizea] == numsb[sizeb]) {
				++j;
				--sizea;
				--sizeb;
			}
			else {
				break;
			}
		}
		if (j == 0) {
			return nullptr;
		}
		else {
			int diff = DIF - j;
			while (diff > 0) {
				ans = ans->next;
				--diff;
			}
		}
		return ans;
	}

	vector<int>numsa;
	vector<int>numsb;
};



int main(int argc, char *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	Solution e;
	ListNode aa(2);
	ListNode bb(3);
	ListNode ee(4);
	aa.next = &bb;
	bb.next = &ee;
	ListNode* p = e.getIntersectionNode(&a, &aa);
	while (p != nullptr) {
		cout << p->val << endl;
		p = p->next;
	}  
	
	return 0;
}
