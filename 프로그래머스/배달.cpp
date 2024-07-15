#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> arr[51];
queue<int> q;
int ans[51];
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    for(int i = 0 ;i<51;i++) {
        ans[i] = 987654321;
    }
    for(vector<int> v : road) {
        arr[v[0]].push_back({v[1],v[2]});
        arr[v[1]].push_back({v[0],v[2]});
    }
    q.push(1);
    ans[1] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0;i < arr[x].size() ; i++) {
            int nx = arr[x][i].first;
            int nextValue = arr[x][i].second;
            if(ans[nx] > ans[x] + nextValue) {
                ans[nx] = ans[x] + nextValue;
                q.push(nx);
            }
        }
    }
    for(int i = 1;i<=N;i++) {
        if(ans[i]<=K) {
            answer++;
        }
    }
    return answer;
}