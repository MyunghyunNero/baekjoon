#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#define PI 3.1415926535
using namespace std;
int d[5000000];
int main()
{	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;           //위치 값 저장
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < a[i].second - i)
			ans = a[i].second - i;       //뒤에서 앞으로 이동한 위치 값
	}
	cout << ans+1;
	return 0;
}