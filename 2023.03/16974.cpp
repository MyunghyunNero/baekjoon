#include <iostream>
using namespace std;
long long dp[51];
long long patty[51];
long long n,x;
long long ans;
long long search(int l,long long xy){
    if(l==0){
        if(xy==0){
            return 0;
        }else if(xy==1){
            return 1;
        }
    }
    if(xy==1){
        return 0;
    }
    else if(xy<dp[l-1]+2){
        return search(l-1,xy-1);
    }else if(dp[l-1]+2==xy){
        return patty[l-1]+1;
    }else if(xy<dp[l-1]+dp[l-1]+3){
        return patty[l-1]+1+search(l-1,xy-dp[l-1]-2);
    }else{
        return 2*patty[l-1]+1;
    }
}
int main(){
    int n;
    cin>>n>>x;
    dp[0]=1;
    patty[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]*2+3;
        patty[i] = patty[i - 1] + 1 + patty[i - 1];
    }
    
    cout<<search(n,x);
}