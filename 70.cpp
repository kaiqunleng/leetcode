#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        
	int a[3] = { 0,1,2 };
	if (n < 3) { return a[n]; }
	int numberone = 1;
	int numbertwo = 2;
	int final = 0;
	for (int i = 3; i <= n; ++i) {
		final = numberone + numbertwo; 
		numberone = numbertwo;
		numbertwo = final;
	}
	return final;
            
    }
};

int main(){
	Solution b ;
	cout<<b.climbStairs(10);
} 
