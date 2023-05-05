#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> t;
vector<pair<int,int>> x;
char arr[7][7];
int n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool ans;
bool check(){
    for(int i=0;i<t.size();i++){
        int x=t[i].first;
        int y=t[i].second;
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            while(nx>0 && nx<=n && ny>0 && ny<=n){
                if(arr[nx][ny]=='S'){
                    return false;
                }
                if(arr[nx][ny]=='O'){
                    break;
                }
                nx+=dx[j];
                ny+=dy[j];
            }
        }
    }
    return true;
}
void dfs(int cnt,int idx){
    if(cnt==3){
        if(check()){
            ans=true;
        }
        return;
    }
    for(int i=idx;i<x.size();i++){
        arr[x[i].first][x[i].second] = 'O';
        dfs(cnt+1,i+1);
        arr[x[i].first][x[i].second] = 'X';
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='T') t.push_back({i,j});
            if(arr[i][j]=='X') x.push_back({i,j});
        }
    }
    dfs(0,0);
    if(ans){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}