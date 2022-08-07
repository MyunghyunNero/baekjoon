#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long n,c,arr[31],ans;
vector<long long> group1;
vector<long long> group2;
void dfs(int s, int e, vector<long long>& v, long long sum)
{
	if(s > e)
	{
		v.push_back(sum);
		return;
	}
	else
	{
		dfs(s+1, e, v, sum);
		dfs(s+1, e, v, sum+arr[s]);
	}
}
int main()
{
	cin >> n >> c;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	// 반으로 나눠서 경우의수 저장  
	dfs(0, n/2, group1, 0);
	dfs(n/2 + 1, n-1, group2, 0);
	sort(group2.begin(), group2.end());
	for(int i = 0; i < group1.size(); i++)  //이분 탐색으로 해야 시간초과 안남 //이유 (2^15)*log (2^15) 이어야 겨우 가능
	{
		ans += upper_bound(group2.begin(), group2.end(), c - group1[i]) - group2.begin();
	}
	cout << ans << '\n';
}