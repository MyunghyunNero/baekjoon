#include <iostream>
using namespace std;
double ans;
long long n,l,w,h;
int main(){
    
    cin>>n>>l>>w>>h;
    int len=min(min(l,w),h);
    double start=0;
    double stop=len;
	for (int i = 0; i < 10000; i++) {
		long double mid = (start + stop) / 2; //현재 탐색하려는 A의 길이를 설정
		if (((long long)(l / mid)) * ((long long)(w / mid)) * ((long long)(h / mid)) >= n) { //상자의 넣을 수 있다면
			start = mid; //시작을 mid로 설정
		}
		else { //상자에 넣을 수 없다면
			stop = mid; //끝을 mid로 설정
		}
	}
    cout << fixed;
    cout.precision(10);
    cout<<stop;
}