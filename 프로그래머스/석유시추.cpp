#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
vector<vector<int>> lands;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visit[501][501];
int xsize;
int ysize;
vector<int> depth;
void bfs(int a,int b, int idx) {
    visit[a][b] = true;
    queue<pair<int,int>> q;
    q.push({a,b});
    lands[a][b]=idx;
    int sum = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < xsize && ny >=0 && ny<ysize) {
                if(!visit[nx][ny] && lands[nx][ny]==1) {
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                    lands[nx][ny]=idx;
                    sum++;
                }
            }
        }
    }
    depth.push_back(sum);
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    lands = land;
    xsize = land.size();
    ysize = land[0].size();
    int idx =2;
    for(int i=0;i<xsize;i++) {
        for(int j=0;j<ysize;j++) {
            if(!visit[i][j] && lands[i][j]==1) {
                bfs(i,j,idx++);
            }
        }
    }
    for(int i=0;i<ysize;i++) {
        int sum = 0;
        set<int> st;
        for(int j=0;j<xsize;j++) {
            if(lands[j][i]!=0) st.insert(lands[j][i]);
        }
        for(auto iter = st.begin();iter != st.end(); iter++) {
            // cout<<i<<' '<<*iter<<' '<<depth[*iter-2]<<'\n';
            sum+=depth[*iter-2];
        }
        answer = max(answer,sum);
    }
    return answer;
}