#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n,d,k,c,ans;
vector<int> v;
unordered_map<int,int> m;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<k;i++){
        m[v[i]]++;
    }
    ans=m.size();
    if(m.find(c)==m.end()) ans++;
    for(int i=k;i<n+k;i++){
        int idx=i;
        if(i>=n){
            idx=i-n;
        }
        m[v[idx]]++;
        m[v[i-k]]--;
        if(m[v[i-k]]==0){
            auto iter=m.find(v[i-k]);
            m.erase(iter);
        }
        int size=m.size();
        if(m.find(c)==m.end()) size++;
        ans=max(size,ans);
    }
    cout<<ans;
}