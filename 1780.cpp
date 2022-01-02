#include <iostream>
using namespace std;
int d[3000][3000];
int unone;
int zero;
int one;
bool same(int a,int b,int n){                     //n*n에서 값이 다 일치하는지 확인하는 함수
    int save=d[a][b];
    for(int i=a;i<a+n;i++){
        for(int k=b;k<b+n;k++){
            if(d[i][k]!=save){
                return false;
            }
        }
    }
    return true;
}
void divide(int a ,int b ,int n){                   //분할해서 값이 같은 종이가 나올때까지 재귀함수 돌리기
    if(same(a,b,n)==true){
        if(d[a][b]==-1){
            unone++;
            return;
        }
        if(d[a][b]==0){
            zero++;
            return;
        }
        if(d[a][b]==1){
            one++;
            return;
        }
    }
    n=n/3;
    divide(a,b,n);
    divide(a,b+n,n);
    divide(a,b+2*n,n);
    divide(a+n,b,n);
    divide(a+n,b+n,n);
    divide(a+n,b+2*n,n);
    divide(a+2*n,b,n);
    divide(a+2*n,b+n,n);
    divide(a+2*n,b+2*n,n);
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            cin>>d[i][k];
        }
    }
    divide(1,1,n);
    cout<<unone<<'\n';
    cout<<zero<<'\n';
    cout<<one<<'\n';
}
