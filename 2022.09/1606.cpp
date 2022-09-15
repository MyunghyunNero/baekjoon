#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long x, y, res = 1;
	cin >> x >> y;
	for (long long i = 1; i < x + y + (!y ? 1 : 0); i++)
		res += 6 * i;
	cout << res + y;
	return 0;
}