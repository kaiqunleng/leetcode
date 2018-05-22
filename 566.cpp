#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int height = nums.size();
		int width = nums[0].size();
		int sum = height*width;
		if (sum != r*c) { return nums; }
		if (r == 1) {
			vector<vector<int>>a(1, vector<int>(sum));
			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					a[0][i*width + j] = nums[i][j];
				}
			}
			return a;
		}

		if (c == 1) {
			vector<vector<int>>a(sum, vector<int>(1));
			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					a[i*width + j][0] = nums[i][j];
				}
			}
			return a;
		}
		
		vector<vector<int>>a(r, vector<int>(c));
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				int xu = i*width + j ;
				a[xu / c ][xu%c] = nums[i][j];
			}
		}
		return a;
	}
};


void main() {

	vector<vector<int>>a(2,vector<int>(5));
	Solution v;
	vector<vector<int>>b = v.matrixReshape(a, 5, 2);
	cout << b.size();

}
