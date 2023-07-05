#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
bool visited[6][6];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool bfs(int startr,int startc,vector<string> place){
    bool check=true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{startr,startc},0});
    visited[startr][startc]=true;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(place[x][y]=='P' && d<=2 && d>0){
            check=false;
            break;
        }
        if(d>=2) continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(!visited[nx][ny] && place[nx][ny]!='X'){
                visited[nx][ny]=true;
                q.push({{nx,ny},d+1});
            }
        }
    }
    return check;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++){
        bool check=true;
        for(int j=0;j<places[i].size();j++){
            for(int k=0;k<places[i][j].size();k++){
                if(places[i][j][k]=='P'){
                    memset(visited,false,sizeof(visited));
                    check= bfs(j,k,places[i]);
                }
                if(!check) break;
            }
            if(!check) break;
        }
        if(check){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    return answer;
}