#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<long long,long long>> x;
int main(){
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        long long z,k;
        cin>>z>>k;
        x.push_back({z,k});
        sum+=k;
    }
    long long s=0;
    long long ans=0;
    sort(x.begin(),x.end());
    for(int i=0;i<n;i++){
        if(s>=sum) break;
        s+=x[i].second*2;
        ans=x[i].first;
    }
    cout<<ans;
}