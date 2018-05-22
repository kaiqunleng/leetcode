#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		
		int mmax = 1;
		int jkl = 1;
		for (int i = 0; i < nums.size()-1; ++i) {
			if (nums[i] == nums[i + 1]) {
				++jkl;
			}
			if (nums[i] != nums[i + 1]) {
				mmax = max(mmax, jkl);
				jkl = 1;
			}
		}
		int sum = accumulate(nums.begin(),nums.end(),0);		
		return mmax;
	}
};
void main() {
	vector<int>a = { 0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1 };
	Solution v;
	int c = v.findMaxConsecutiveOnes(a);
	cout << c;
}
