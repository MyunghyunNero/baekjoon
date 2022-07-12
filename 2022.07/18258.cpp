#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, d;
	queue<int> q; string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		if (s == "push") {
			cin >> d;
			q.push(d);
		}
		else if (s == "pop") {
			if (q.size() == 0) 
                cout << "-1\n";
			else {
				d = q.front();
				q.pop();
				cout << d << "\n";
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.size() == 0) 
            cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (s == "back") {
			if (q.size() == 0) 
            cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}