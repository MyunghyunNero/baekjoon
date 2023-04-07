#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long ans;
vector<pair<long long,long long>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        long long s,e;
        cin>>s>>e;
        v.push_back({s,e});
    }
    long long maxx;
    sort(v.begin(),v.end());
    ans+=v[0].second - v[0].first;
    maxx=v[0].second;
    for(int i=1;i<n;i++){
        
        if(v[i].first>=maxx){
            ans+=v[i].second-v[i].first;
        }else if(v[i].first<maxx && v[i].second>maxx){
            ans+=v[i].second-maxx;
        }
        maxx=max(maxx,v[i].second);
    }
    cout<<ans;
}