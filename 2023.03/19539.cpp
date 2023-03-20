#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    int n;
	cin >> n;
	vector<int> v(n);

	int d=0, r=0;
	for (auto& c : v) {
		cin >> c;
		d += c / 2;
		r += c % 2;
	}

	if ((d-r)%3==0 && d>=r)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
    
}