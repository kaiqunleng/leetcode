#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
#include<forward_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		numss = nums;
		vector<int>::iterator it = numss.begin();
		end = numss.end();
		permutation(it, it);
		return perm;

	}



	void permutation(vector<int>::iterator str, vector<int>::iterator begin) {
		if (begin == end) {
			perm.push_back(numss);
		}
        
		for (vector<int>::iterator it = begin; it != end; ++it) {

			int num = *it;
			*it = *begin;
			*begin = num;
			permutation(str, begin + 1);
			 num = *it;
			*it = *begin;
			*begin = num;
		}



	}
	vector<int>numss;
	vector<vector<int>> perm;
	vector<int>::iterator end;
};



int main(int argc, char *argv[])
{
	vector<int>a = { 1,2,3 };
	Solution b;
	vector<vector<int>>c = b.permute(a);
	for (auto i : c) {
		for (auto j : i) {

			cout << j << "";

		}
		cout << endl;
	}






	return 0;
}


