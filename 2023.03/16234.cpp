#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,l,r;
int arr[51][51];
bool check[51][51];
bool bfs(int a,int b){ //변경이 일어났는지
    queue<pair<int,int>> q;
    int sum=0;
    int cnt=0;
    q.push({a,b});
    check[a][b]=true;
    vector<pair<int,int>> v;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        sum+=arr[x][y];
        cnt++;
        v.push_back({x,y});
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=n || ny<0 ||ny>=n) continue;
            if(abs(arr[x][y]-arr[nx][ny])>=l && (abs(arr[x][y]-arr[nx][ny])<=r)){
                if(!check[nx][ny]){
                    check[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    for(int i=0;i<v.size();i++){
        arr[v[i].first][v[i].second]=sum/cnt;
    }
    if(cnt>1){
        return true;
    }else{
        return false;
    }
}
int main(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    bool allChange=true;
    do{
        memset(check,false,sizeof(check));
        bool change=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i][j]) continue;
                if(bfs(i,j)){
                    change=true;
                }
            }
        }
        if(change){
            allChange=true;
            ans++;
        }else{
            allChange=false;
        }
    }while(allChange);
    cout<<ans;
}