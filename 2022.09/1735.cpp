#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int gcd(int x, int y){
	if(y==0) return x;
	return gcd(y, x%y);
}
int main(){
	cin >> a >> b >> c >> d;
	a *= d;
	c *= b;
	a += c;
	b *= d;
	int g = gcd(a,b);
	cout << a/g << ' ' << b/g << '\n';
	return 0;
}