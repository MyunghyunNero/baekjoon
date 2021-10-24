#include <iostream>
using namespace std;
int coin[11];
int main(){
    int k;
    int n;
    int cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    while(k){
        for(int i=0;i<n;i++){
            if(k<coin[i]){
                k=k-coin[i-1];
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}


