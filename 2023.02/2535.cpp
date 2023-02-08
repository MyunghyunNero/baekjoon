#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end(),greater<>());
    bool check=false;
    int point=v[0].second.first;
    for(int i=1;i<3;i++){
        if(point != v[i].second.first) check=true;
    }
    if(check){
        for(int i=0;i<3;i++){
            cout<<v[i].second.first << " "<<v[i].second.second<<'\n';
        }
    }else{
        for(int i=0;i<2;i++){
            cout<<v[i].second.first<< " "<<v[i].second.second<<'\n';
        }
        for(int i=3;i<n;i++){
            if(v[i].second.first != point){
                cout<<v[i].second.first<< " "<<v[i].second.second<<'\n';
                break;
            }
        }
    }
}