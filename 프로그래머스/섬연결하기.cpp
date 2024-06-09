#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool check[101];
vector<vector<int>> cost;
int ans;
vector<pair<int,int>> arr[101];
void dijkstra(int start) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    check[start]=true;
    for(pair<int,int> a : arr[start]) {
        pq.push(a);
    }
    while(!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        if(check[p.second]) continue;
        ans+=p.first;
        check[p.second] = true;
        for(pair<int,int> a : arr[p.second]) {
            if(!check[a.second]) pq.push(a);
        }
        
    }
}
int solution(int n, vector<vector<int>> costs) {
    cost = costs;
    int start = costs[0][0];
    for(vector<int> v : costs) {
        arr[v[0]].push_back({v[2],v[1]});
        arr[v[1]].push_back({v[2],v[0]});
    }
    dijkstra(start);
    return ans;
}