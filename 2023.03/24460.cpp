#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1025][1025];
int n;

int search(int size,int r,int c){
    int sub=size/2;
    if(size==1){
        return dp[r][c];
    }else{
        
        int one=search(sub,r,c);
        int two=search(sub,r,c+sub);
        int three=search(sub,r+sub,c);
        int four=search(sub,r+sub,c+sub);
        int minv=one;
        minv=min(minv,two);
        minv=min(minv,three);
        minv=min(minv,four);
        int sec=9876554321;
        if(one!=minv){
            sec=min(one,sec);
        }
        if(two!=minv){
            sec=min(two,sec);
        }
        if(three!=minv){
            sec=min(three,sec);
        }
        if(four!=minv){
            sec=min(four,sec);
        }
        return sec;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dp[i][j];
        }
    }
    cout<<search(n,0,0);
}