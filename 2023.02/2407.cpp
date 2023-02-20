#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long n, m, ans;
string comb[101][101];

string numToString(string a, string b){
    long long sum = 0;
    string str;
    while(a.size() || b.size() || sum){
        if(a.size()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }
        str.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(str.begin(),str.end());
    return str;
}

string combination(int n, int m){
    if(n == m || m == 0) return "1";
    string &str = comb[n][m];
    if(str != "") return str;
    str = numToString(combination(n-1,m-1), combination(n-1,m));
    return str;
}

int main(){
    cin >> n >> m;
    cout << combination(n,m);
}