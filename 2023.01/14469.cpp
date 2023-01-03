#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        if(ans<v[i].first){
            ans=v[i].first+v[i].second;
        }else{
            ans+=v[i].second;
        }
    }
    cout<<ans;
}