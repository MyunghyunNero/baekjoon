#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool same(vector<vector<int>>& v,int a,int b, int n){         //n*n 범위에서 값이 다 일치 하는지
    for(int i=a;i<a+n;i++){
        for(int k=b;k<b+n;k++){
            if(v[i][k]!=v[a][b]){
                return false;
            }
        }
    }
    return true;
}
void divide(vector<vector<int>>& v,int a, int b, int n){          ////4분할하는 함수
    if(same(v,a,b,n)==true){               //값이 일치하면 그 값 하나 출력
        cout << v[a][b];
    }else{           
        cout <<'(';                         //값이 일치하지 않으면 4등분 왼쪽 위. 오른쪽 위 . 왼쪽 아래, 오른쪽 아래 순으로 출력
        n=n/2;
        for(int i=0;i<2;i++){
            for(int k=0;k<2;k++){
                divide(v,a+i*n,b+k*n,n);
            }
        }
        cout<<')';
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        string s;
        cin >>s;
        for(int k=0;k<n;k++){
            v[i].push_back(s[k]-'0');
        }
    }
    divide(v,0,0,n);
}