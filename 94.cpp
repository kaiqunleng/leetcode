
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode * p = root;
		while (p || !tt.empty()) {
			if (p) { 
			tt.push(*p);
			p = p->left;
			}
			else {
				TreeNode*q = &tt.top();
				result.push_back(q->val);
				tt.pop();
				p = q->right;
			}
		}
		
		return result;

	}
	stack<TreeNode>tt;
	vector<int>result;
};

int  main()
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	a.left = &b;
	a.right = &c;
	b.right = &d;
	Solution dd;
	vector<int>res = dd.inorderTraversal(&a); 
	for (auto i : res) {
		cout << i << endl;
	}
	return 0;
}
