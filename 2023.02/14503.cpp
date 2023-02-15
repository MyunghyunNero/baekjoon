#include <iostream>
#include <queue>
using namespace std;
int arr[51][51];
int n,m;
int startI,startJ;
int direct;
int cnt;
bool isClean(int a,int b){
    bool allClaer=true;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx<0||nx>=n || ny<0 || ny>=m) continue;
        if(arr[nx][ny]==0){
            allClaer=false;
            break;
        }
    }
    return allClaer;
}
bool isBack(int a,int b){
    bool back=true;
    if(direct==0){
        if(arr[a+1][b]==1) back=false;
    }else if(direct==1){
        if(arr[a][b-1]==1) back=false;
    }else if(direct==2){
        if(arr[a-1][b]==1) back=false;
    }else{
        if(arr[a][b+1]==1) back=false;
    }
    return back;

}
bool isFront(int a,int b){
    bool front=false;
    if(direct==0){
        if(arr[a-1][b]==0) front=true;
    }else if(direct==1){
        if(arr[a][b+1]==0) front=true;
    }else if(direct==2){
        if(arr[a+1][b]==0) front=true;
    }else{
        if(arr[a][b-1]==0) front=true;;
    }
    return front;
}
void spin(){
    direct-=1;
    if(direct==-1) direct=3;
}
int main(){
    cin>>n>>m;
    cin>>startI>>startJ>>direct;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({startI,startJ});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(arr[x][y]==0) {
            cnt++;
            arr[x][y]=2; 
        }//청소
        if(isClean(x,y)){
            if(isBack(x,y)){
                if(direct==0){
                    q.push({x+1,y});
                }else if(direct==1){
                    q.push({x,y-1});
                }else if(direct==2){
                    q.push({x-1,y});
                }else{
                    q.push({x,y+1});
                }
            }else{
                cout<<cnt;
                return 0;
            }
        }else{
            spin();
            if(isFront(x,y)){
                if(direct==0){
                    q.push({x-1,y});
                }else if(direct==1){
                    q.push({x,y+1});
                }else if(direct==2){
                    q.push({x+!,y});
                }else{
                    q.push({x,y-1});
                }
            }else{
                q.push({x,y});
            }
        }
    }

}