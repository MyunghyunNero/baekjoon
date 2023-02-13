#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        int ans=0;
        while(n){
            n/=2;
            ans++;
        }
        cout<<ans+m<<'\n';
    }
}