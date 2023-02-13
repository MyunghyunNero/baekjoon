#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int arr[101][101];
bool check[101][101];
int ans=1;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void rain(int rain){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<=rain) check[i][j]=true;
        }
    }
}
void rainBFS(int a,int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    check[a][b]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i =0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(!check[nx][ny]) {
                q.push({nx,ny});
                check[nx][ny]=true;
            };
        }
    }
}
int main(){
    int maxH=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(maxH<arr[i][j]) maxH=arr[i][j];
        }
    }
    for(int i=1;i<=maxH;i++){
        memset(check,false,sizeof(check));
        rain(i);
        int cnt=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(check[j][k]==false){
                    cnt++;
                    rainBFS(j,k);
                }
            }
        }
        if(ans<cnt) ans=cnt;
    }
    cout<<ans;
}