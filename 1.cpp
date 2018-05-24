#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0;i<nums.size()-1;++i){
            for(int j =i+1;j<nums.size();++j){
                 if(nums[i]+nums[j]==target){
                     a.push_back(i);
                     a.push_back(j);
                 }   
            }
        }
        return a;
    }
    vector<int>a;
};
int main(){
	
	vector<int>a  ={1,2,3,4,5,6};
	int target = 11;
	Solution d;
	vector<int>c  = d.twoSum(a,target);
	for(auto i:c){
		cout<<i<<endl;
	}
	
	
	
	
	
	
}
