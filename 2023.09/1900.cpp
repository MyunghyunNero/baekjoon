#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second > b.second){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    map<int,int> m;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        m[i+1]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a=v[i].first+v[i].second*v[j].first;
            int b=v[j].first+v[j].second*v[i].first;
            if(a>b){
                m[i+1]++;
            }else{
                m[j+1]++;
            }
        }
    }
    vector<pair<int,int>> ans(m.begin(),m.end());
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<'\n';
    }

}