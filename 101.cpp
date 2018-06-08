
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
	stack<TreeNode*> preorderTraversal(TreeNode* root) {
		TreeNode * p = root;
		while (p || !tt.empty()) {
			if (p) {
				tt.push(*p);
				result.push(p);
				p = p->left;
			}
			else {
				result.push(nullptr);
				TreeNode*q = &tt.top();
				tt.pop();
				p = q->right;
			}
		}
		result.push(nullptr);
		return result;
	}

	stack<TreeNode*> preorderTraversal2(TreeNode* root) {
		TreeNode * p = root;
		while (p || !tt2.empty()) {
			if (p) {
				tt2.push(*p);
				result2.push(p);
				p = p->right;
			}
			else {
				result2.push(nullptr);
				TreeNode*q = &tt2.top();
				tt2.pop();
				p = q->left;
			}
		}
		result2.push(nullptr);
		return result2;
	}

	bool isSymmetric(TreeNode* root) {
		preorderTraversal(root);
		preorderTraversal2(root);
		while (!result.empty() && !result2.empty()) {
			TreeNode*p = result.top();
			result.pop();
			TreeNode*q = result2.top();
			result2.pop();
			if ((p == nullptr&&q != nullptr) || (q == nullptr&&p != nullptr)) {
				return false;
			}
			if ((p&&q)&&(p->val!=q->val)) {
				return false;
			}

		}
		return true;
	}

	stack<TreeNode>tt;
	stack<TreeNode*>result;
	stack<TreeNode>tt2;
	stack<TreeNode*>result2;
};

int  main()
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	TreeNode d(4);
	a.left = &b;
	a.right = &c;
	Solution dd;
	bool flag = dd.isSymmetric(&a);
	cout << flag;
	return 0;
}
