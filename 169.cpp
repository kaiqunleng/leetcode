
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];    
    }
};

int main(){
	vector<int>a ={1,1,2,2,2,2,3};
	Solution b ;
	int c  =b.majorityElement(a);
	cout<<c;
	
	
	
	
}
