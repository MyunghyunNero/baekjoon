#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a,b,c;
int n,k;
int ans=-1;
vector<int> arr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        arr.push_back(k);
    }
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=2;i--){
        a=arr[i];
        b=arr[i-1];
        c=arr[i-2];
        if(a<b+c){
            ans=a+b+c;
            break;
        }
    }
    cout<<ans;
}