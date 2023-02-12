#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N, x, y;
double ans;
vector<pair<double, double>> v;

double Product(int v1, int v2, int v3)
{
	double x1 = v[v1].first;
	double x2 = v[v2].first;
	double x3 = v[v3].first;
	double y1 = v[v1].second;
	double y2 = v[v2].second;
	double y3 = v[v3].second;

	double tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	double tmp2 = x2 * y1 + x3 * y2 + x1 * y3;

	double result = tmp1 - tmp2;
	return result / 2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 1; i < N - 1; i++)
		ans += Product(0, i, i + 1);

	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << '\n';
}