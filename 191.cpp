#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            if((n&1)==1){
                ++res;
            }
            n= n/2;          
        }
        return res;
    }
};
int main(){
	uint32_t v = 10;
	Solution bb ;
	cout<<bb.hammingWeight(v);
	
}
