#include <iostream>
#include <vector>
using namespace std;
int cnt,n;
int main(){
    cin>>n;
    vector<int> v(n+1,0);
    v[1]=1;
    for(int i=2;i<=n;i++){
        int minval=999999999;
        for(int j=1;j*j<=i;j++){
            int temp= i-j*j;
            minval = min(minval,v[temp]);
        }
        v[i]=minval+1;
    }
    cout<<v[n];
}       