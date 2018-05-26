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
        ListNode* p=head;//快指针
        ListNode* q=head;//慢指针
        while(p!=nullptr&&q!=nullptr&&p->next!=nullptr){//边界条件是出现空指针，就返回false；
            q=q->next;
            p=p->next->next;//空指针没有next，否则会出现NullPointerException问题
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
