#include <iostream>
using namespace std;
bool prime[100001];
int dp[100001];
int main(){
    int a,b;
    cin>>a>>b;
    prime[0]=true;
    prime[1]=true;
    for(int i=2;i<=100000;i++){
        if(prime[i]==false){
            dp[i]=1;
            for(int k=i*2;k<=100000;k+=i){
                prime[k]=true;
            }
        }
    }
    for(int i=2;i<=b;i++){
        if(dp[i]==0){
            int k=2;
            while(1){
                if(i%k==0){
                    dp[i]=dp[i/k]+1;
                    break;
                }
                k++;
            }
        }
    }
    int ans=0;
    for(int i=a;i<=b;i++){
        if(prime[dp[i]]==false){
            ans++;
        }
    }
    cout<<ans;
}