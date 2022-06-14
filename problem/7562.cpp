#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int arr[301][301];
bool check[301][301];
int dx[] = { 1,2,-1,-2,1,2,-1,-2 };
int dy[] = { 2,1,2,1,-2,-1,-2,-1 };
int t, l, startx,starty,endx,endy;

void reset(int l) {
	for (int i = 0; i < l; i++) {
		for (int k = 0; k < l; k++) {
			arr[i][k] = 0;
			check[i][k] = false;
		}
	}
}
int bfs(int x, int y) {
	
	queue<pii> p;
	p.push(pii(x, y));
	while (!p.empty()) {
		x = p.front().first;
		y = p.front().second;
		int before = arr[y][x];
		if (x == endx && y == endy) {
			return arr[endy][endx];
		}
		p.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
				if (!check[ny][nx]) {
					p.push(pii(nx, ny));
					check[ny][nx] = true;
					arr[ny][nx] = before + 1;
				}
			}
		}
	}
}

int main()	
{
	cin >> t;
	while (t--) {
		cin >> l;
		cin >> startx >> starty;
		cin >> endx >> endy;
		bfs(startx, starty);
		cout << arr[endy][endx] << '\n';
		reset(l);
	}
}
