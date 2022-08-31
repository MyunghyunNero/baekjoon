#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l,n,s,e,ans;
vector<int> arr;
int main(){
    cin >> l;
    for(int i=0;i<l;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cin>>n;
    sort(arr.begin(),arr.end());
    for(int i=0;i<l;i++){
        if(arr[i]>=n){
            e=arr[i];
            if(i>0){
                s=arr[i-1];
            }
            break;
        }
    }
    int ans=(n-s)*(e-n);
    if(ans==0){
        cout <<ans;
    }else{
        cout<<ans-1;
    }
}