#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool check[201];
int cnt;
vector<vector<int>> arr;
void bfs(int a, int n){
    queue<int> q;
    q.push(a);
    check[a]=true;
    while(!q.empty()) { 
        int x=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!check[i] && arr[x][i]==1){
                q.push(i);
                check[i]=true;
            } 
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    arr = computers;
    for(int i=0;i<n;i++){
        if(!check[i]){ 
            bfs(i,n);
            cnt++;
        }
    }
    return cnt;
}