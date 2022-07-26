#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;  //세번째 인자에 greater을 넣어서 오름차순 정렬
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << q.top().second << "\n";
				q.pop();
			}
		}
		else {
			q.push({abs(temp),temp});             //첫번째 인자를 우선으로비교하고 같으면 두번쨰 인자 비교해서 우선순위에 들어감
		}
	}
	return 0;

}