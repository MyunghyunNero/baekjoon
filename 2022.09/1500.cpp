#include <iostream>
using namespace std;
int main(){
    long long s,n;
    cin>>s>>n;
    long long k=s/n;
    long long t=s%n;
    long long ans=1;
    for(int i=0;i<t;i++){
        ans*=(k+1);
    }
    for(int i=0;i<n-t;i++){
        ans*=k;
    }
    cout<<ans;
}