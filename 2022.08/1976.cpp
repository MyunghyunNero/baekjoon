#include <iostream>
#include <vector>
using namespace std;
int parent[201];
int n, m;
int find(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}
void unionfunc(int x,int y){
  x = find(x);
  y = find(y);
  parent[x] = y;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <= 200; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            int temp;
			cin >> temp;
			if (temp == 1) unionfunc(i, j);
		}
	}
	int post, cur;
	bool check = true;
	cin >> post;
	for (int i = 1; i < m; i++) {
		cin >> cur;
		if (find(post) != find(cur)) {
            check = false;
            break;
        }
		post = cur;
	}
	if (check) cout << "YES";
	else cout << "NO";
}