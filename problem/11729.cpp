#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define PI 3.1415926535
void hanoi(int, int, int);
int num=0;
using namespace std;
vector<int> f;
vector<int> t;
void hanoi(int n,int from,int by,int to){
	if (n == 1) {                                   //탈출 조건
		cout << from << ' ' << to << '\n';
		num++;
	}
	else {
		hanoi(n - 1,from ,to,by );                  //from칸에서 마지막 것 제외하고 by칸으로 이동
		cout << from << ' ' << to << '\n';          // 마지막 것 to칸으로 이동
		hanoi(n-1,by ,from,to );                    //by칸으로 옮겼던 것들 to칸으로 이동
		num++;
	}
}
int main()
{
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n,1,2,3);
	
	
	return 0;
}