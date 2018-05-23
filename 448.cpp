#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()==0){
            return vector<int>();
        }
       sort(nums.begin(),nums.end());
        int mag = nums.size();
        nums.push_back(mag);                         //后面插入元素数量
        nums.insert(nums.begin(),0);                //前面插入0
        for(int i = 0;i<nums.size()-1;++i){
          if(nums[i+1]-nums[i]==0||nums[i+1]-nums[i]==1){
                continue;
            }
            int nnum = nums[i+1]-nums[i]-1;
            while(nnum>0){
                aa.push_back(nums[i+1]-nnum);
                --nnum;
            }
        }
        if(nums[mag]!=mag){
            aa.push_back(mag);
        }
        return aa;
    }
             vector<int>aa;
}; 

int main(){
	Solution a;
	vector<int>bb = {2,2,3,5,3,2,4,5};
	vector<int>cc = a.findDisappearedNumbers(bb);
	for(auto j :cc){
		cout<<j<<endl;
	}
	
}
