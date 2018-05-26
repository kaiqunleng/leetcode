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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        while(l1!=nullptr){
            total.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2!=nullptr){
            total.push_back(l2->val);
            l2 = l2->next;
        }
        if(total.size()==0){
            return nullptr;
        }
        sort(total.begin(),total.end());
        int first  = total.front();
        total.pop_front();
        ListNode * q = new ListNode(first);
        ListNode *tail = q;
        while(total.size()!=0){
            int num = total.front();
            total.pop_front();
             ListNode * p  = new ListNode(num); 
            tail->next  = p;
            tail = tail->next;
        }   
        return q;
    }    
    deque<int>total;
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
 	   
 	   	   ListNode node11(2);
 	   ListNode node22(3);
 	   ListNode node33(3);
 	   ListNode node44(4);
 	   ListNode node55(6);
 	   node11.next = &node22;
 	   node22.next = &node33;
 	   node33.next = &node44;
 	   node44.next = &node55;
  
  
     Solution b ;
	 ListNode *q = b.mergeTwoLists(&node,&node11);
	 	if(q){
	
		 while(q!=nullptr){
		   cout<<q->val<<endl; 
		   q =q->next;	
		 }
        }      
	
	
	
	
	
	
	
	
	
	
	return 0;
}


