#include <iostream>
#include <vector>
using namespace std;
int dp[10001];
int n,ans;
int main(){
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        int last=0;
        int time=0;
        for(int j=0;j<b;j++){
            int c;
            cin>>c;
            if(dp[c]>time){
                last=c;
                time=dp[c];
            }
        }
        dp[i]= dp[last]+a;
    }
    for(int i=1;i<=n;i++){
        ans=max(dp[i],ans);
    }
    cout<<ans;
}
