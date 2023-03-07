#include <iostream>
using namespace std;
int n;
int arr[17][17];
int sum=0;
void dfs(int a,int b,int status){//status가 0이면 가로 1이면 세로 2이면 대각선
    if(a==n && b==n){
        sum++;
        return;
    }
    if(status==0){
        if(b+1<n && arr[a][b+1]!=1){
            dfs(a,b+1,0);
        }
        if(b+1<n && a+1<n && arr[a][b+1]!=1 && arr[a+1][b+1]!=1 && arr[a+1][b]!=1){
            dfs(a+1,b+1,2);
        }
    }else if(status==1){
        if(a+1<n && arr[a+1][b]!=1){
            dfs(a+1,b,1);
        }
        if(b+1<n && a+1<n && arr[a][b+1]!=1 && arr[a+1][b+1]!=1 && arr[a+1][b]!=1){
            dfs(a+1,b+1,2);
        }
    }else if(status==2){
        if(b+1<n && arr[a][b+1]!=1){
            dfs(a,b+1,0);
        }
        if(a+1<n && arr[a+1][b]!=1){
            dfs(a+1,b,1);
        }
        if(b+1<n && a+1<n && arr[a][b+1]!=1 && arr[a+1][b+1]!=1 && arr[a+1][b]!=1){
            dfs(a+1,b+1,2);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,1,0);
    cout<<sum;
}