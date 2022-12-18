#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    ans=arr[n-1];
    for(int i=0;i<n;i++){
        if(ans<arr[i]*(n-i)) ans=arr[i]*(n-i);
    }
    cout<<ans;
}