#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> >picture; // 학생 번호, 추천 수
int n;

bool comp(pair<int, int>a, pair<int, int> b)
{
	return a.first < b.first;
}


void choose()
{
	int min_count = 987654321;

	for (int i = 0; i < picture.size(); i++)
	{
		min_count = min(min_count, picture[i].second);
	}

	for (int i = 0; i < picture.size(); i++)
	{
		if (min_count == picture[i].second)
		{
			picture.erase(picture.begin()+i); // 등록된게 시간 순이니까 젤 앞에 꺼!
			break;
		}

	}

}


int main()
{
	int k,student;
	int flag;
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> student;
		flag = 0;
		for (int i = 0; i < picture.size(); i++)//이미 추천된 후보인지 판단
		{
			if (student == picture[i].first)
			{
				flag = 1; //이미 추천되어 있음
				picture[i].second++; // 추천횟수 증가
				break;
			}
		}

		if (flag == 0)//새로운 후보다
		{
			if (picture.size() < n)//아직 액자 남았다
			{
				picture.push_back(make_pair(student, 1));
			}

			else if (picture.size() == n) //액자 가득 참
			{
				choose(); // 사진 한개 삭제
				picture.push_back(make_pair(student, 1));

			}
		}
	}

	sort(picture.begin(), picture.end(), comp);

	for (int i = 0; i < picture.size(); i++)
	{
		cout << picture[i].first << " ";
	}

	return 0;
}