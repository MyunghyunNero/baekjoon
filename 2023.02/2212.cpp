#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k;
vector<int> v;
vector<int> diff;
int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int startx=v[0];
    int endx=v[n-1]; 
    for(int i=1;i<n;i++){
        diff.push_back(v[i]-v[i-1]);
    }
    sort(diff.begin(),diff.end(),greater<>());
    int ans=endx-startx;
    for(int i=0;i<k-1;i++){
        if(i>=diff.size()) continue;
        ans-=diff[i];
    }
    cout<<ans;
}