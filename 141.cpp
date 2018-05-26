#include<iostream>
#include<deque>
#include<algorithm>
 
 
 using namespace std;
 
 
 
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
 
 
 class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p=head;//��ָ��
        ListNode* q=head;//��ָ��
        while(p!=nullptr&&q!=nullptr&&p->next!=nullptr){//�߽������ǳ��ֿ�ָ�룬�ͷ���false��
            q=q->next;
            p=p->next->next;//��ָ��û��next����������NullPointerException����
            if(p==q)return true;
        }
        return false;
        
    }
};

int main(){
	
	ListNode node(1);
	node.next = &node;
	Solution b ;
	bool flag = b.hasCycle(&node);
	cout<<flag;
	
	
	return 0;
}
