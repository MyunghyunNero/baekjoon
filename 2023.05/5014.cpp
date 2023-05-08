#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans[1000001];
bool visited[1000001];
vector<int> dx;
int f,s,g,u,d;
void bfs(int start){
    visited[start]=true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int nx=x+dx[i];
            if(nx>0&&nx<=f){
                if(!visited[nx]){
                    visited[nx]=true;
                    q.push(nx);
                    ans[nx]=ans[x]+1;
                }
            }
        }
    }
    
}
int main(){
    cin>>f>>s>>g>>u>>d;
    dx.push_back(u);
    dx.push_back(d*-1);
    bfs(s);
    if(visited[g]){
        cout<<ans[g];
    }else{
        cout << "use the stairs";
    }
}