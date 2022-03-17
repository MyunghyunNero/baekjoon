#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, a, c, b, d;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int arr[101][101];
bool check[101][101];
int bfs(int x, int y) {
	int cnt = 0;
	queue<pii> q;
	q.push(pii(x, y));
	check[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny < m && ny>=0) {
				if (!check[nx][ny] && arr[nx][ny] != -1) {
					q.push(pii(nx, ny));
					check[nx][ny]=true;
				}
			}
		}
		cnt++;
	}
	return cnt;

}
int main() {
	cin >> n >> m >> k;
	while (k--) {
		cin >> a >> b >> c >> d;
		for (int y = b; y < d; y++) {
			for (int x = a; x < c; x++) {
				arr[y][x] = -1;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int s = 0; s < m; s++) {
			if (check[i][s] == false && arr[i][s] != -1) {
				ans.push_back(bfs(i, s));
			}
		}
	}
	sort(ans.begin(), ans.end());
	int len = ans.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++) {
		cout << ans[i]<<" ";
	}
	
	
}
