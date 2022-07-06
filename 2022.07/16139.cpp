#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sum[2000001][26];     
string s;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>s;
    int n;
    cin>>n;
    int len=s.size();
    for(int i=1;i<=len;i++){          //난 1부터 시작함 
        for(int k=0;k<26;k++){
            sum[i][k]=sum[i-1][k];     //첫번째 문자열 부터 차근차근 누적합해주기
        }
        sum[i][s[i-1]-97]++;            //이번에 나온 문자 1더하기
    }
    while(n-->0){
        int l,r;
        char c;
        cin >>c>>l>>r;
        cout<<sum[r+1][c-97]-sum[l][c-97]<<'\n';
    }

}