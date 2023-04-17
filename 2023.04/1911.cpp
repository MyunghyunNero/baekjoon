#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;
int n,l;
int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int nul=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int s=v[i].first;
        int e=v[i].second;
        if(nul>e)continue;
        if(nul>s){
            ans+=(e-nul)/l+1;
            int remain=(e-nul)%l;
            if(remain==0){ 
                remain+=l;
                ans--;
            }
            nul=e+l-remain;
        }else{
            ans+=(e-s)/l+1;
            int remain=(e-s)%l;
            if(remain==0) {
                remain+=l;
                ans--;
            }
            nul=e+l-remain;
        }
    }
    cout<<ans;
}