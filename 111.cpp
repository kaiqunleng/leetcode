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
    int minDepth(TreeNode* root) {
     if(root ==nullptr){
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left==0&&right>0){
            return right+1;
        }
        if(right==0&&left>0){
            return left+1;
        }
        return left>right? right+1:left+1;   
    } 
    
};

int main(){
	TreeNode a(1);
	TreeNode b(3);
	TreeNode c(4);
	a.left = &b;
	b.right = &c;
	Solution dd;
	cout<<dd.minDepth(&a);
} 
