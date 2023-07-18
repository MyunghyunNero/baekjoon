#include <iostream>
#include <queue>
using namespace std;
int arr[3][3];
bool visited[3][3];
int n;
bool check=false;
void bfs(){
    visited[0][0]=true;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        cout<<x<<' '<<y<<"\n";
        q.pop();
        if(x==n-1 && y==n-1){
            check=true;
            break;
        }
        int nx=x+arr[x][y];
        if(!visited[nx][y] && nx<n){
            visited[nx][y]=true;
            q.push({nx,y});
        }
        int ny=y+arr[x][y];
        if(!visited[x][ny] && ny<n){
            visited[x][ny]=true;
            q.push({x,ny});
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
    bfs();
    if(check){
        cout<<"HaruHaru";
    }else{
        cout<<"Hing";
    }
}