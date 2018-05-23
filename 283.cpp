#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0;i<nums.size();++i){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i] = nums[cand];
                nums[cand] = temp;
                ++cand;
            }   
        }
    }
    int cand =0;
};

int main(){
	vector<int>nums ={1,2,3,0,0,4,1,3,0,0,5};
	Solution a;
	a.moveZeroes(nums);
	for(auto i: nums){
		cout<<i<<endl;
	}
}
