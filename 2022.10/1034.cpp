#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
int ans;
vector<string> v;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s); 
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(v[i][j]=='0') cnt++;
        }
        if(cnt%2!=k%2 || cnt>k) continue;
        int cnt2=0;
        for(int j=0;j<n;j++){
            if(v[i]==v[j]){
                cnt2++;
            }
        }
        if(cnt2>ans) ans=cnt2;
    }
    cout<<ans;
}