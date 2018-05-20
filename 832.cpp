#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
         int height = A.size();
         int  width = A[0].size();
        for(int i = 0;i<height; ++i){
            for(int j =0;j<width/2;++j){
                int temp = A[i][j];
                A[i][j] = !(A[i][width-1-j]);   
                A[i][width-1-j]  = !temp;
                
            }
            if(width%2==1){
                A[i][width/2] =  ! A[i][width/2];
            }
        }
        
      return A;       
    
        
    }
};
 int main(){
         vector<vector<int>> A = { {1,0,0},{0,0,1},{0,1,0}};
         Solution a;
         a.flipAndInvertImage(A);
		  for( auto i : A){
		  	for( auto j : i){
		  		cout<<j<<" ";
			  }
		  	cout<<endl;
		  }	
 	
 } 
