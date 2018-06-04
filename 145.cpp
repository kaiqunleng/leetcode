
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
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode* p = root;	TreeNode*r = nullptr;
		while (p || !tt.empty()) {
			if (p) {
				tt.push(p);
				p = p->left;
			}
			else {
				p = tt.top();
				if (p->right && p->right!= r) {
					p = p->right;
					//tt.push(*p);
					//p = p->left;
				}
				else {
				 //   TreeNode ee = tt.top();
				//	p = &ee;
					//r = p;
				//	res.push_back(p->val);
					//tt.pop();
					tt.pop();
					res.push_back(p->val);
					r = p;
					p = nullptr;
				}




			}




		}

		return res;
	}




	stack<TreeNode*>tt;
	vector<int>res;


};

int main(){
	
	
		TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
//	TreeNode d(4);
	//a.left = &b;
	a.right = &c;
//	b.right = &d;
	Solution dd;
	vector<int>ddw = dd.postorderTraversal(&a);
	for (auto j : ddw) {
		cout << j;
	}
	
	
	
	
} 
