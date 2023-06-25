#include <iostream>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int N;
double dir[4];
bool arr[50][50];
double ans;
void dfs(int idx,int x,int y,double sum){
    if(idx==N){
        ans+=sum;
        return;
    }
    for(int i=0;i<4;i++){
        if(dir[i]==0) continue;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!arr[nx][ny]){
            arr[nx][ny]=true;
            dfs(idx+1,nx,ny,sum*dir[i]);
            arr[nx][ny]=false;
        }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<4;i++){
        cin>>dir[i];
        dir[i]=dir[i]/100.0;
    }
    arr[25][25]=true;
    dfs(0,25,25,1.0);
    cout.precision(11);cout << fixed;
    cout<<ans;
}