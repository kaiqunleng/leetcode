#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i =0;i<size;){          
            if(nums[i]==i+1){
                ++i;  
            }
            else if(nums[i]<=i||nums[i]>size||nums[nums[i]-1]==nums[i]){
                nums[i] = nums[--size ];
            }
            else{
                  swap(nums[i],nums[nums[i]-1]);
            }
        }
        return size+1;
    }
};

int main(){
	vector<int>a ={2,3,4};
	Solution b ;
	int c = b.firstMissingPositive(a);
	cout<<c<<endl;
	return  0;	
}
