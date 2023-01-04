#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<2*n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans=9999999;
    sort(v.begin(),v.end());    
    for(int i =0 ;i<n;i++){
        int team = v[i] + v[2*n-1-i];
        if(team < ans) ans=team;
    }
    cout<<ans;
}