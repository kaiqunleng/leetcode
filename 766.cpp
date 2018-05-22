#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;




class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		if (matrix.size() == 1 || matrix[0].size() == 1) {
			return true;
		}
     
		int height = matrix.size();
		int width = matrix[0].size();
		for (int i = 0; i < width; ++i) {
			int cand = matrix[0][i];
			for (int j = 1, k = 1; j < height&&i + k < width; ++j, ++k) {
				if (cand != matrix[j][i + k]) {
					return false;
				}
			}
		}

		for (int i = 0; i < height; ++i) {
			int candc = matrix[i][0];
			for (int j = 1, k = 1; i + j < height&&k < width; ++j, ++k) {
				if (candc != matrix[i + j][k]) {
					return false;
				}
			}
		}
		return true;
	}
};






void main() {
	vector<int>a = { 1,2,3,4 };
	vector<int>b = { 1,1,2,3 };
	vector<vector<int>>c = { a,b };
	Solution cc; 
	bool l = cc.isToeplitzMatrix(c);
	cout << l;







}
