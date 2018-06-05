#include<iostream>
#include<vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root ==nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left>right? left+1:right+1;   
    } 
    
    
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        else{
            preorder(root);
        }
        return flag;
        
        
    }
    void preorder(TreeNode*root){
        if(!root){
            return;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if(abs(left-right)>1){flag = false;
        }
        
        preorder(root->left);
        preorder(root->right);
    }
    
    
    bool flag = true;
};

int main(){
	TreeNode a(1);
	TreeNode b(3);
	TreeNode c(4);
	TreeNode d(3);
	TreeNode e(5);
	a.left = &b;
	b.left = &c;
	a.right = &d;
	c.left = &e;
	Solution dd;
	cout<<dd.isBalanced(&a);	
}

