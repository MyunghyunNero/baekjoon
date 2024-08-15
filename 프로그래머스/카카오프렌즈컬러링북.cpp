#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int cnt;
int maxExtent;
int rowSize;
int colSize;
bool visit[101][101];
vector<vector<int>> pictures;
void dfs(int color, int a,int b) {
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = true;
    cnt++;
    int extent = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >=rowSize || ny < 0 || ny >= colSize) continue;
            if(pictures[nx][ny] == color && !visit[nx][ny]) {
                q.push({nx,ny});
                visit[nx][ny] = true;
                extent++;
            }
        }
    }
    maxExtent = max(maxExtent, extent);
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visit[i][j] = 0;
        }
    }
    cnt = 0;
    maxExtent =0;
    rowSize = m;
    colSize = n;
    pictures = picture;
    vector<int> answer(2);
    for(int i = 0 ;i<m;i++) {
        for(int j=0;j<n;j++) { 
            if(pictures[i][j]!=0 && !visit[i][j]) {
                dfs(pictures[i][j],i,j);
            }
        }
    }
    answer[0]=cnt;
    answer[1]=maxExtent;
    return answer;
}