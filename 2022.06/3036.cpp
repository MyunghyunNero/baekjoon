#include <iostream>
using namespace std;
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}
int main(){
    int n,a,b;
    cin >>n;
    cin >>a;
    while(--n){
        cin>>b;
        int tmp=gcd(a,b);
        cout <<a/tmp<<'/'<<b/tmp<<'\n';
    }
}