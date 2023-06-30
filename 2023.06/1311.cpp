#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> work[21];
vector<int> dp;
int countbit(int num){
    int cnt=0;
    while(num){
        cnt+=(num&1);
        num>>=1;
    }
    return cnt;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            work[i].push_back(a);
        }
    }
    for(int i=0;i<pow(2,n);i++){
        dp.push_back(987654321);
    }
    dp[0]=0;
    for(int i=0;i<pow(2,n);i++){
        int x=countbit(i);
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))){
                dp[i|1<<j]=min(dp[i|1<<j],dp[i]+work[x][j]);
            }
        }
    }
    cout<<dp[dp.size()-1];
    
}