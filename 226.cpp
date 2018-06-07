#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root==nullptr){
             return nullptr;
         } 
        else{
            exchange(root);
            return root;
        }
    }
    void exchange(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr||root->right!=nullptr){
            TreeNode*temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        exchange(root->left);
        exchange(root->right);
    }    
};

int main(){
	TreeNode  a(8);
	TreeNode  b(7);
	TreeNode  c(9);
	a.left = &b;
	a.right = &c;
	Solution dd;
	TreeNode* p = dd.invertTree(&a) ;
	cout<<p->val<<endl;
	cout<<p->left->val<<endl;
	cout<<p->right->val<<endl; 
	
	
	
}
