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
    int maxDepth(TreeNode* root) {
        if(root ==nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left>right? left+1:right+1;   
    } 
};

int main(){
	TreeNode a(1);
	TreeNode b(3);
	TreeNode c(4);
	a.left = &b;
	b.right = &c;
	Solution dd;
	cout<<dd.maxDepth(&a);
	
	
	
	
} 
