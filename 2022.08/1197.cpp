#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int v,e;
long long ans;
bool visit[10001];
vector<pair<int,int>> node[10001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }
    pq.push({0,1}); //가중치, 노드
    while(!pq.empty()){
        int w=pq.top().first;
        int next=pq.top().second;
        pq.pop();
        if(visit[next]) continue;
        visit[next]=true;
        ans+=w;
        for(int i=0;i<node[next].size();i++){
            int nextw=node[next][i].second;
            int nextnode=node[next][i].first;
            pq.push({nextw,nextnode});
        }
    }
    cout <<ans;
}