#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int df[]={0,0,0,0,1,-1};
int tomato[101][101][101];
int n,m,f;
int day;
queue<pair<pair<int,int>,int>> q;
void bfs(){
    while (!q.empty()) {
		int h = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = h + df[i];
			if (nx >= 0 && ny >= 0 && nh >= 0 && nx < m && ny < n && nh < f) {
				if (tomato[nh][ny][nx] == 0) {
					tomato[nh][ny][nx] = tomato[h][y][x] + 1;
					q.push({{nh, ny},nx});
				}
			}
		}
	}
}
int main(){
    cin>>m>>n>>f;
    for(int i=0;i<f;i++){
        for(int j=0;j<n;j++){
            for(int t=0;t<m;t++){
                cin>>tomato[i][j][t];
                if(tomato[i][j][t]==1){
                    q.push({{i,j},t});
                }
            }
        }
    }
    bfs();
    for (int i = 0; i < f; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				day = max(day, tomato[i][j][k]);
			}
		}
	}
    cout <<day-1;
}