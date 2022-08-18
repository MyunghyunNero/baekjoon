#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int node, edge, a, b;
		cin >> node>> edge;
		for (int i = 0; i < edge; i++) 
			cin >> a >> b;
		cout << node-1 << '\n';
	}
	return 0;
}