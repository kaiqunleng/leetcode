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
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }

    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // ÿ�δ� preorder ͷ��ȡһ��ֵ mid����Ϊ���ĸ��ڵ�
        // ��� mid �� inorder �� ��λ�ã��� mid ǰ�沿�ֽ���Ϊ �������������Ҳ�����Ϊ����������

        if(i >= j)
            return NULL;

        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};


int main(){
	
	vector<int>a = {8,4,3,3,7};
	vector<int>b = {3,3,4,7,8};
	Solution c ;
	TreeNode*s = c.buildTree(a,b);
	
	
	
	
	
	
}
