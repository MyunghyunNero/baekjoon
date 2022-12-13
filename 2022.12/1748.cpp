#include <iostream>
using namespace std;
int n,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i*=10){
        ans+=n-i+1;
    }
    cout<<ans;
}