#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

string s, e, q;
set<string> st;

int Change(string s) {
	string si = s.substr(0, 2);
	string boon = s.substr(3,2);
	return 100 * stol(si) + stol(boon);
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> e >> q;
	string str, name;
	int cnt = 0;

	int start = Change(s);
	int end = Change(e);
	int qu = Change(q);

    while (cin.eof() == false) {
		cin >> str;
		string si = str.substr(0, 2);
		string boon = str.substr(3, 2);
		cin >> name;

		int time = Change(str);

		if (time <= start) {
			
			st.insert(name);
		}
		else if (end <= time && time <= qu) {
			if (st.find(name) != st.end()) {
				cnt++;
				auto it = st.find(name);
				st.erase(it);
			}
		}
	}
    cout<<cnt;
}