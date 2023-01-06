#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    int ans= abs(a-b);
    for(int i=0;i<n;i++){
        int mhz;
        cin>>mhz;
        ans = min(ans, abs(mhz-b)+1);
    }
    cout<<ans;

}