#include <iostream>
using namespace std;
int n,k;
int arr[51];
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[a]++;
    }
    for(int i=1;i<=n;i++){
        while(arr[i]>1 && i+k<=n){
            arr[i+k]++;
            arr[i]--;
        }
    }
    bool check= true;
    for(int i=1;i<=n;i++){
        if(!arr[i]) check =false;
    }
    if(check){
        cout<<1;
    }else{
        cout<<0;
    }
}