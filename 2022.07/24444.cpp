#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,r;
int check[100001];
bool visit[100001];
int cnt;
vector<int> v[100001];
void bfs(){
    queue<int> q;
    q.push(r);
    visit[r]=true;
    while(!q.empty()){
        int next=q.front();
        q.pop();
        check[next]=++cnt;
        for(int i=0;i<v[next].size();i++){
            if(!visit[v[next][i]]){
                q.push(v[next][i]);
                visit[v[next][i]]=true;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n>>m>>r;
    for(int i=1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    bfs();
    for(int i=1;i<=n;i++){
        cout <<check[i]<<'\n';
    }
}