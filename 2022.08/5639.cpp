#include <iostream>
#include <vector>
using namespace std;
int tree[10001];
void postOrder(int start, int end) {
	if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int right = start + 1;
	while (right<end) {
		if (tree[start]<tree[right]) {
			break;
		}
		right++;
	}
	postOrder(start+1, right);
	postOrder(right, end);
	cout << tree[start] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	int a = 0;
	while (cin >> num) {
		tree[a++] = num;
	}
	postOrder(0,a);
	return 0;
}