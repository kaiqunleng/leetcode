#include<vector>
#include<algorithm>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return lkqversion(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
    TreeNode* lkqversion(vector<int>&inorder,int i,int j,vector<int>&postorder,int ii,int jj){
        if(i>=j)   {return nullptr;}
        TreeNode*q = new TreeNode(postorder[jj-1]);
        auto l = find(inorder.begin()+i,inorder.begin()+j,postorder[jj-1]);
        int dis = l - inorder.begin()-i;
        q ->left = lkqversion(inorder,i,i+dis,postorder,ii,ii+dis);
        q ->right = lkqversion(inorder,i+dis+1,j,postorder,ii+dis,jj-1);
        return q;
    }
};

int main(){
	vector<int>a = {9,3,15,20,7};
	vector<int>b = {9,15,7,20,3};
	Solution c ;
	TreeNode*s = c.buildTree(a,b);
	
}
