#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0){
            return res;
        }
        string path;
        parentheses(n,n,path,res);
        return res;
    }
    
    void parentheses(int leftRem,int rightRem,string&path,vector<string>&paths){
        if(leftRem<0||rightRem<0){
            return ;
        }
        if(leftRem>0){
            path.push_back('(');
            parentheses(leftRem-1,rightRem,path,paths);
            path.pop_back();
        }
        if(leftRem<rightRem){
            path.push_back(')');
            rightRem -= 1;
            if(rightRem == 0){
                paths.push_back(path);
            }
            parentheses(leftRem,rightRem,path,paths);
            path.pop_back();
        }
    }
}; 

int main(){
	Solution bb ;
	vector<string> res =bb.generateParenthesis(3); 
	for(auto i:res){
		cout<<i<<endl;
	}
	
	
}
