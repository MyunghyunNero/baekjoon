#include <iostream>
using namespace std;
int ans;
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    if(a%b==0){
        cout<<0;
        return 0;
    }
    if(a>b)a=a%b;
    for(int i=0;i<n;i++){
        a*=10;
        ans=a/b;
        a=a%b;
    }
    cout<<ans;
}