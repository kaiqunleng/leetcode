#include<iostream>
#include<string>
using namespace std;
 
class Solution {
public:
	long long myAtoi(string str) {
		if (str.size() == 0) {
			return 0;
		}
		int length = str.size();
		int j = 0;
		int jj = 0;
		for (int i = 0; i<length; ++i) {
			if (str[i] == ' ') {
				continue;
			}
			else if (str[i] == '-') {
				ispos = false;
				j = i + 1;
				break;
			}
            else if (str[i] == '+') {
				j = i + 1;
				break;
			}
			else if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
				j = i;
				break;
			}
			else {
				return 0;
			}
		}
		int k = j;
		if (str[j] - '0'>9 || str[j] - '0'<0) {
			return 0;
		}
		else {
			while (str[k] - '0' <= 9 && str[k] - '0' >= 0) {
				if (k<length) {
					++k;
					++jj;
				}
				else { break; }
			}
		}

		int* cand = new int[jj];
		for (int i = 0; i<jj; ++i) {
			cand[i] = str[j + i] - '0';
		}
		long long jkl = 1; long long res = 0;
		for (int i = jj - 1; i >= 0; --i) {
			res += cand[i] * jkl;
			jkl *= 10;
			if (res > 2147483647&&ispos==true) {
				res = 2147483647;
				break;
			}
			if (ispos == false) {
				if (res*-1 < -2147483648) {
					res = -2147483648;
					break;
				}
			}
            if(i<=jj-11&&cand[i]!=0){
                            if(ispos==false){
                long long res2 = -2147483648;
                return res2;
            }
            else{
               long long res2 = 2147483647;
                return res2;
            }
            }
		}
         if (ispos == false) {
             return -res;
         }
		return res;
	}
	bool ispos = true;
	
};


int main(){
	Solution b;
	string s = "42321213";
	long long res = b.myAtoi(s);
	cout<<res;	
}
