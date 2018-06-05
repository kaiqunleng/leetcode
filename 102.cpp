#include<queue>
#include<vector>
#include<iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };




class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
               result.push_back(temp);
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
	TreeNode e(5);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	Solution ee;
	vector<vector<int>>de  = ee.levelOrder(&a);
	for(auto i :de){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
