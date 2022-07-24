#include <iostream>
using namespace std;
#define mod 1000
long long n,m;
long long matrix[6][6];
long long temp[6][6];
long long ans[6][6];
void divide(long long x){
    if(x==1){
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                ans[i][k]=temp[i][k]%1000;
        }
    }
        return;
    }
    if(x%2==1){
        divide(x-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=0;
                for(int t=0;t<n;t++){
                    ans[i][j]+=temp[i][t]*matrix[t][j];              //홀수 이면 기본 행렬 곱해주기
                    
                }
                ans[i][j]%=mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                temp[i][k]=ans[i][k];                             //결과값 저장
        }
    }
        return;
    }
    divide(x/2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=0;
            for(int t=0;t<n;t++){
                ans[i][j]+=temp[i][t]*temp[t][j];                       //짝수이면 거듭곱 행렬 곱하기
            }
            ans[i][j]%=mod;
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            temp[i][k]=ans[i][k];
        }
    }
    
}
int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cin>>matrix[i][k];
            temp[i][k]=matrix[i][k];
        }
    }
    divide(m);
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout <<ans[i][k]<<' ';
        }
        cout<<'\n';
    }
}