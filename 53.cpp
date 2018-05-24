#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size()>0) {
			int mmax = nums[0];
			int siz = nums.size();
			int* aa = new int[siz + 1];
			aa[0] = 0;
			for (int i = 1; i<siz + 1; ++i) {
				aa[i] = nums[i-1] + aa[i - 1];
			}
			for (int i = 0; i<nums.size(); ++i) {
				for (int j = 0; j<i+1; ++j) {
					mmax = max(mmax, aa[i + 1] - aa[j]);
				}
			}
			return mmax;
		}
	}
};


int main(int argc, char *argv[])
{
	vector<int>a = { -2,-1 };
	Solution b;
	int c = b.maxSubArray(a);
	cout << c;
	return 0;
}


