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
		ListNode* p = head;//��ָ��
		ListNode* q = head;//��ָ��
		while (p != nullptr&&q != nullptr&&p->next != nullptr) {//�߽������ǳ��ֿ�ָ�룬�ͷ���false��
			q = q->next;
			p = p->next->next;//��ָ��û��next����������NullPointerException����
			if (p == q) {
 				int jk = 1;     //ѭ���Ľ�������
				int minj = 0;     //��ͷ�ڵ㿪ʼ����ÿ��ѭ������ߵĲ�������Сֵ��
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
	//			lenght = minj + jk;     ����
				
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
