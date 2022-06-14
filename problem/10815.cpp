#include <iostream>
#include <vector>
using namespace std;
int sang[20000002];
int ans[500001];
int main(){
    int n,m;
    int t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >>t;
        sang[t+10000000]=1;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        if(sang[t+10000000]==1){
            ans[i]=1;
        }
    }
    for(int i=0;i<m;i++){
        cout <<ans[i]<<" ";
    }


}