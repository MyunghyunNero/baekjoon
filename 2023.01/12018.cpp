#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int p,l;
        cin>>p>>l;
        vector<int> v;
        for(int k=0;k<p;k++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),greater<int>());
        if(p<l){
            ans.push_back(1);
        }else{
            ans.push_back(v[l-1]);
        }
    }
    sort(ans.begin(),ans.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(m>=ans[i]){
            cnt++;
            m-=ans[i];
        }
    }
    cout<<cnt;
}