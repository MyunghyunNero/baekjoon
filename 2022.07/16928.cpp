#include <iostream>
#include <queue>
using namespace std;
int visit[102];
int snake[102];
int n,m;
queue<int> q;
void bfs(int x){
    q.push(x);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=1;i<=6;i++){
            int nx=x+i;
            if(nx<=100){
                while(snake[nx]!=0){
                    nx=snake[nx];
                }
                if(!visit[nx]){
                    q.push(nx);
                    visit[nx]=visit[x]+1;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i =0 ;i <n+m ;i++){
        int a,b;
        cin>>a>>b;
        snake[a]=b;
    }
    bfs(1);
    cout<<visit[100];
}