#include<iostream>
#include<vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    if(head == nullptr){
        return nullptr;
    }    
    
    ListNode* p =nullptr;
    while(head->next!=nullptr){
        cand.push_back(head->val);
        head = head->next;
    }
     p = head;
     ListNode*q  = new ListNode(0);
     ListNode*tail  = q;
     q->val = p->val;
     while(cand.size()!=0){
        int dd = cand.back();
         cand.pop_back();
         ListNode* ta = new ListNode(0);
         ta->val = dd;
         tail->next = ta;
         tail = tail->next;
     }
     tail->next = nullptr;
        
     return q;   
        
        
    }
    
    
    vector<int>cand;
};
 
 
 int main(){
 	   ListNode node(1);
 	   ListNode node2(2);
 	   ListNode node3(3);
 	   ListNode node4(4);
 	   ListNode node5(5);
 	   node.next = &node2;
 	   node2.next = &node3;
 	   node3.next = &node4;
 	   node4.next = &node5;
		node5.next =nullptr;
		Solution b;
		ListNode * q = b.reverseList(&node);
		if(q){
	
		 while(q!=nullptr){
		   cout<<q->val<<endl; 
		   q =q->next;	
		 }
        }  
 }
