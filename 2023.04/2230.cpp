#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long m;
long long ans;
vector<long long> v;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long s=0,e=0;
    while(s<n){
        if(e==n) break;
        if(v[e]-v[s]>=m) {
            ans=v[e]-v[s];
            s++;
        }else{
            e++;
        }
    }
    cout<<ans;
}