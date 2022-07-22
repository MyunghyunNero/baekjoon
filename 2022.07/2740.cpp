#include <iostream>
using namespace std;
int n,m,k;
int matrix1[101][101];
int matrix2[101][101];
int ans[101][101];
int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>matrix1[i][k];
        }
    }
    cin>>m>>k;
    for(int i=0;i<m;i++){
        for(int t=0;t<k;t++){
            cin>>matrix2[i][t];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int t=0;t<m;t++){
                ans[i][j]+=matrix1[i][t]*matrix2[t][j];
            }
            cout << ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}