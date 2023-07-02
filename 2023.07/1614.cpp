#include <iostream>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long ans=0;
    if(n==1){
        ans+=(k*8);
    }else if(n==5){
        ans=4;
        ans+=(k*8);
    }else{
        ans+=8*(k/2);
        if(k%2==0){
            ans+=n-1;
        }else{
            ans+=(8-n+1);
        }
    }
    cout<<ans;
}