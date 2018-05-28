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
	bool isPalindrome(ListNode* head) {
		while (head != nullptr) {
			int num = head->val;
			nums.push_back(num);
			head = head->next;
		}
		int size = nums.size();
		for (int i = 0, j = size - 1; i < j; ++i, --j) {
			if (nums[i] != nums[j]) {
				return false;
			}
		}

		return true;
	}
	vector<int>nums;
};






int main(int argc, char *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(2);
	ListNode d(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	Solution e;
	bool f = e.isPalindrome(&a);
	cout << f;
	return 0;
}
