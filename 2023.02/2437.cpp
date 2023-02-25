#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=0;i<n;i++){
        if(v[i]>ans){
            break;
        }
        ans+=v[i];
    }
    cout<<ans;
}