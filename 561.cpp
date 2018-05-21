#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0;i<nums.size();i+=2){
               sum  =sum +nums[i];
        }
        return sum;
    }
};




int main(){
	
	vector<int> b  = {1,4,3,2,8,9};
    Solution a;
	int sum = a.arrayPairSum(b);
	cout<<sum;    
	
	
} 
