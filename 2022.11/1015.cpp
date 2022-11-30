#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int start=0;
    vector<pair<int,int>> v;
    vector<int> temp(n+1);
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back({a,start});
        start++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ans[v[i].second]=i;
    }
    for(int i=0;i<n;i++){
        cout<< ans[i] << " ";
    }

}