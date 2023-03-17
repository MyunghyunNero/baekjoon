#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int cnt = 0;

	for (int i = 0; i < s.length(); i++)
	{
		// P라면 개수 증가
		if (s[i] == 'P')
		{
			cnt++;

			continue;
		}

		// 현재 A이고 앞에 두개 이상이 P이고 뒤에가 P이면 PPAP
		if (cnt >= 2 && s[i + 1] == 'P')
		{
			// PPAP는 P로 치환 -> cnt--
			cnt--;

			// 뒤에 P까지 확인했으므로 i++
			i++;
		}
		else
		{
			cout << "NP\n";

			return 0;
		}
	}

	// P로 끝나야 PPAP
	if (cnt == 1)
	{
		cout << "PPAP\n";
	}
	else
	{
		cout << "NP\n";
	}

	return 0;
}