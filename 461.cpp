
#include<iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int res = 0 ;
        while(z){
            if((z&1)==1){
                ++res;
            }
            z= z/2;          
        }
        return res;   
    }
};

int main(){
	Solution cc ;
	cout<<cc.hammingDistance(3,6);
} 
