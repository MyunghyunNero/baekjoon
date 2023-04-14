#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[300001];
int arr[300001];
queue<int> q;
int n,m,k,x;
int main(){
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0;i<=n;i++){
        arr[i]=3000001;
    }
    q.push(x);
    arr[x]=0;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0;i<v[a].size();i++){
            if(arr[v[a][i]]>arr[a]+1){
                arr[v[a][i]]=arr[a]+1;
                q.push(v[a][i]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==k) {
            cout<<i<<'\n';
            ans++;
        }
    }
    if(ans==0) cout<<-1;

}