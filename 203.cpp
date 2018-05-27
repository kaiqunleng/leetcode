#include<iostream>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
  
  class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head ==nullptr){
            return nullptr;
        }
         
		ListNode* ptr = head;
		while (ptr&&ptr->val == val) {
			ptr = ptr->next;
		}
        
        ListNode*copy = ptr;
        if(ptr){
        int num = ptr->val;
        ListNode* ppt = new ListNode(num);
        ListNode*tail = ppt;
        ListNode*copy2 = ptr->next;
        while(copy2!=nullptr){
            if(copy2->val!=val){
                ListNode *p =  new ListNode(copy2->val);
                tail->next = p;
                tail =tail->next;
            }
            copy2 = copy2->next;
        }
        
    
        return ppt;  }
        else{
            return nullptr;
        }
    }
    
};


int main(){
	
	 ListNode a(1);
	 ListNode b(2);
	 ListNode c(3);
	 ListNode d(4);
	 ListNode e(5);
	 a.next = &b;
	 b.next = &c;
	 c.next = &d;
	 d.next = &e;
	 Solution h ;
	 ListNode* p = h.removeElements(&a,3);
	 while(p!=nullptr){
	 	
	 	cout<<p->val<<endl;
	 	p = p->next;
	 	
	 	
	 }	
	
	
	
}
