#include<iostream>
#include<list>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
       for(int i=0;i<s.size();++i){
           if(paren.size()==0){
           paren.push_front(s[i]);}
           else{
               char c = paren.front();
               char p = s[i];
               if(c ==p-1||c==p-2){
                   paren.pop_front();
               }
               else{
                   paren.push_front(p);
               }
           }
           
       }
        if(paren.empty()){
           return true; 
        }else{
            return false;
        }
    }
    list<char>paren;
    
};


int main(int arc,char**p){
	
	string s = "(){}[]";
	Solution b;
	cout<< b.isValid(s)<<endl;
	return 0;
	
	
	
}
