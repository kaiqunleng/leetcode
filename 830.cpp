#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == S[i + 1]) {
				int j = 1;
				int q = i + 1;
				while (q != S.size() - 1) {
					if (S[q] == S[q + 1]) {
						++j;
                        ++q;
					}
					else {
						break;
					}


				}
				if (j > 1) {
					vector<int>cand = { i,i + j };
					answer.push_back(cand);
                    i = i+j;
				}

			}
		}
        return answer;
	}
	vector<vector<int>>answer;
};


int main(){
	
	string s = "ssssdddnnnewqqs";
	Solution a;
	vector<vector<int>>b = a.largeGroupPositions(s);
	for(auto i:b){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
		
	}
	
	
	
	
	
}
