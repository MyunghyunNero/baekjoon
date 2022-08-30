#include <iostream>
using namespace std;
int n,a,b;
int ans;
int main(){
    cin>>n>>a>>b;
    a=a-1;
    b=b-1;
    while(a!=b){
        a=a/2;
        b=b/2;
        ans++;
    }
    cout<<ans;
}