#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr[20001];
int dp[20001];
int maxNode;
void dfs() {
    queue<int> q;
    dp[1]=0;
    q.push(1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int v : arr[node]) {
            if(dp[v]>dp[node]+1){
                q.push(v);
                dp[v] = dp[node]+1;
                maxNode= max(maxNode, dp[node]+1);
            }
            
        }   
    }
    
}
int solution(int n, vector<vector<int>> edge) {
    int answer =0;
    for(int i=0;i<20001;i++) {
        dp[i]=50001;
    }
    for(vector<int> v : edge) {
        arr[v[0]].push_back(v[1]);
        arr[v[1]].push_back(v[0]);
    }
    dfs();
    for(int i=0;i<20001;i++) {
        if(dp[i]==maxNode){
            answer++;
        }
    }
    return answer;
}