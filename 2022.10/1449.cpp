#include <iostream>
using namespace std;
int a[1001];
int n,l;
int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[k]=1;
    }
    int ans=0;
    for(int i=1;i<=1000;i++){
        if(a[i]==1){
            ans++;
            i+=(l-1);
        }
    }
    cout <<ans;
}