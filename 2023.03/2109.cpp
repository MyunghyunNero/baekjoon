#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int,int>> v;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first>b.first){
        return true;
    }else if(a.first==b.first){
        if(a.second>b.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int main(){
    cin>>n;
    int maxday=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(maxday<a){
            maxday=a;
        }
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int sum=0;
    for(int i=maxday;i>0;i--){
        for(int j=0;j<v.size();j++){
            if(i<=v[j].second){
                sum+=v[j].first;
                v.erase(v.begin()+j);
                break;
            }
        }
    }
    cout<<sum;
}