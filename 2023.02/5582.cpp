#include <iostream>
#include <string>
using namespace std;
int ans;
int dp[4001][4001];
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int s1Len=s1.size();
    int s2Len=s2.size();
    for(int i=0;i<s1Len;i++){
        for(int j=0;j<s2Len;j++){
            if(s1[i]==s2[j]){
                if(i==0||j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
}