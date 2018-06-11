#include<iostream>
#include<vector>
#include<queue>
using namespace std; 


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
             vector<int>temp;
     if(root==nullptr){
         return result;;
     }
       queue<TreeNode*>cand;
        cand.push(root);
        cand.push(nullptr);
       while(!cand.empty()){
           TreeNode*q = cand.front();
           cand.pop();
           if(q!=nullptr){
               temp.push_back(q->val);
               if(q->left){cand.push(q->left);}
               if(q->right){cand.push(q->right);}
           }
           else{
               result.insert(result.begin(),temp);
               temp.resize(0);
               if(!cand.empty()){
                   cand.push(nullptr);
               }   
           } 
       } 
       return result;    
    }
       vector<vector<int>>result;
};

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	a.left = &b;
	b.right = &c;
	c.left= &d;
	Solution res;
	vector<vector<int>>result = res.levelOrderBottom(&a);
    for(auto i :result){
    	for(auto j :i){
    		cout<<j<<" ";
		}
    	cout<<endl;
	}	
	
	
}


