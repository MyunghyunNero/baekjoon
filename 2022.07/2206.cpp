#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int visited[1001][1001][2];
int arr[1001][1001];
queue<pair<pair<int,int>,int>> q;
int bfs(vector<string> &arr) {
    q.push({ {0,0},0 });
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) { //도착지에 도달하면 return
            return visited[x][y][block];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n&& ny >= 0 && ny < m) {
                //다음 칸이 벽이고 뚫을 수 있을 때
                if (arr[nx][ny] == '1' && block==0) {
                    q.push({ {nx,ny} ,1 });
                    visited[nx][ny][block + 1] = visited[x][y][block] + 1;
                }
                //다음 칸이 0이고 방문하지 않았을 때
                else if (arr[nx][ny] == '0' && visited[nx][ny][block] == 0) {
                    q.push({ {nx,ny},block });
                    visited[nx][ny][block] = visited[x][y][block] + 1;
                }
            }
        }

    }
    return -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n>>m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout <<bfs(arr);
    return 0;
}