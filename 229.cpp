#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return aa;
        }
        if(nums.size()==1){
            aa.push_back(nums[0]);
            return aa;
        }
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i =0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]){
                ++count;
                 if(i==nums.size()-2&&count>nums.size()/3){
                    aa.push_back(nums[i]);
                }
            }
            if(nums[i]!=nums[i+1]&&count>nums.size()/3){
                aa.push_back(nums[i]);
                count = 1;
            }
            if(nums[i]!=nums[i+1]&&count<=nums.size()/3){
                count = 1;
            }     
        }
        if(nums.size()==2&&count>nums.size()/3&&nums[0]!=nums[1]){
            aa.push_back(nums[1]);
       }
        return aa;
    }
    vector<int>aa;
};


int main(){
	vector<int>a  ={1,2,4,3,3,3,6,6};
	Solution b ;
	vector<int> c = b.majorityElement(a);
	for(auto i:c){
		cout<<i<<endl;		
	}
	return 0;
}
