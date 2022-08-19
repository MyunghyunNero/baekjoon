#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int parent[200999];
int cnt[200999];
int t,n;
int find(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}
int unionfunc(int x,int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        cnt[x]+=cnt[y];
        cnt[y]=1;
    }
    parent[y] = x;
    return cnt[x];
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        map<string,int> m;
        string s1,s2;
        int ans=0;
        int node=1;
        for(int i=1;i<=2*n;i++){  
            cnt[i]=1;
            parent[i]=i;
        }
        for(int i=1;i<=n;i++){
            cin>>s1>>s2;
            if(!m.count(s1))m[s1]=node++;
            if(!m.count(s2))m[s2]=node++;
            ans=unionfunc(m[s1],m[s2]);
            cout <<ans<<"\n";
        }
    }
}