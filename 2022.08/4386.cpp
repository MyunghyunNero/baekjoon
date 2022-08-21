#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;
double ans;
bool visit[101];
vector<pair<double,double>> node;
priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
double getDist(int a, int b) {
    return sqrt((node[a].first - node[b].first) * (node[a].first - node[b].first) + 
            (node[a].second - node[b].second) * (node[a].second - node[b].second));
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >>n;
    for(double i=0;i<n;i++){
        double a,b;
        cin>>a>>b;
        node.push_back({a,b});
    }
    pq.push({0.0,0}); //가중치, 노드
    while(!pq.empty()){
        double w=pq.top().first;
        int next=pq.top().second;
        pq.pop();
        if(visit[next]) continue;
        visit[next]=true;
        ans+=w;
        for(int i=0;i<n;i++){
            if(next==i) continue;
            pq.push({getDist(next,i),i});
        }
    }
    cout <<ans;
}