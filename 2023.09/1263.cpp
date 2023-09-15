#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second < b.second){
        return false;
    }else{
        return true;
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int time=v[0].second;
    for(int i=0;i<n;i++){
        time = min(time,v[i].second);
        time -= v[i].first;
    }
    if(time < 0){
        cout<< -1;
    }else{
        cout << time;
    }
}