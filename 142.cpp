#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode *head) {
		ListNode* cand = head;
		ListNode* p = head;//快指针
		ListNode* q = head;//慢指针
		while (p != nullptr&&q != nullptr&&p->next != nullptr) {//边界条件是出现空指针，就返回false；
			q = q->next;
			p = p->next->next;//空指针没有next，否则会出现NullPointerException问题
			if (p == q) {
 				int jk = 1;     //循环的结点的数量
				int minj = 0;     //从头节点开始到达每个循环结点走的步数的最小值。
				ListNode* ui = q;
		//		while (ui->next != q) {
		//			++jk;
		//			ui = ui->next;
		//		}
				while (cand != q) {
					++minj;
					cand = cand->next;
				}
				ListNode *uj = q;
				while (uj->next != q) {
					ListNode* pp = head;
					int jj = 0;
					while (pp != uj) {
						 ++jj;
						 pp = pp->next;
						 }
					minj = min(jj,minj);
					uj = uj->next;
				}
	//			lenght = minj + jk;     多余
				
				for (int i = 0; i < minj; ++i) {
					head = head->next;
				}
				
				
				
				return  head;  
			}
		}
		return nullptr;

	}
	int lenght = 0;
};
int main(int argc, char *argv[])
{

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &a;
	Solution cc;
	ListNode*q = cc.detectCycle(&a);
	cout << q->val;
	return 0;
}
