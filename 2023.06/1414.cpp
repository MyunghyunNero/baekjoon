#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
string lan[51];
int parent[51];
int n;
int sum=0;
int ans;
bool visited[51];
vector<pair<int,int>> v[51];
int findparent(int x){
    if(x==findparent(parent[x])){
        return x;
    }else{
        return findparent(parent[x]);
    }
}
void uni(int x,int y){
    x=findparent(x);
    y=findparent(y);
    parent[y]=x;
}
int findDis(int i,int j){
    int len=0;
    if(lan[i][j]>='a' && lan[i][j]<='z'){
        len=lan[i][j]-'a'+1;
    }else if(lan[i][j]>='A'&&lan[i][j]<='Z'){
        len=lan[i][j]-'A'+1;
    }
    return len;
}
void prim(int start){
    visited[start]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<v[start].size();i++){
        int dis=v[start][i].first;
        int node=v[start][i].second;
        pq.push({dis,node});
    }
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        ans+=dis;
        visited[node]=true;
        for(int i=0;i<v[node].size();i++){
            int nextdis=v[node][i].first;
            int nextnode=v[node][i].second;
            if(!visited[nextnode]){
                pq.push({nextdis,nextnode});
            }
        }
    }

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>lan[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int len=findDis(i,j);
            sum+=len;
            if(i==j) continue;
            if(len!=0){
                v[i].push_back({findDis(i,j),j});
                v[j].push_back({findDis(i,j),i});
            }
        }
    }
    bool check=true;
    prim(0);
    for(int i=0;i<n;i++){
        if(!visited[i]) check=false;
    }
    if(check){
        cout<<sum-ans;
    }else{
        cout<<-1;
    }
}