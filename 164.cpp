#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maximumGap(vector<int>& nums) {
        if(nums.size()<2){return 0;}
		min = *min_element(nums.begin(),nums.end());
		max = *max_element(nums.begin(), nums.end());
		vector<vector<int>>cc(nums.size()+1);
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == max) {
				cc[nums.size()].push_back(max);
			}
			else {
				int num = (nums[i] - min)*(nums.size() + 1) / (max - min);
				cc[num].push_back(nums[i]);
			}
		}
		for (int i = 0; i < cc.size(); ++i) {
			if (cc[i].empty()) {
				continue;
			}
			dd.push_back(cc[i]);
			
	   }
        if(dd.size()==1){
            return 0;
        }
		for (int i = 0; i < dd.size() - 1; ++i) {
			int num = *min_element(dd[i + 1].begin(), dd[i + 1].end())-*max_element(dd[i].begin(),dd[i].end());
			diif.push_back(num);
		}

		return *max_element(diif.begin(),diif.end());
	}

	int min=0;
	int max=0;
	vector<int>diif;
	vector<vector<int>>cc;
	vector<vector<int>>dd;
};
int main(){
     vector<int>a ={1,2,100};
     Solution b ;
     int c = b.maximumGap(a);
     cout<<c;
	
	return 0;
}
