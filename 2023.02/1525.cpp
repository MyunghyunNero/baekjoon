#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string start;
string endstr;
set<string> visited;
int bfs(){
    queue<pair<string,int>> q;
    q.push({start,0});
    visited.insert(start);
    while(!q.empty()){
        string cur=q.front().first;
        int time= q.front().second;
        q.pop();
        if(cur==endstr) return time;
        int zero=cur.find('0');
        int x=zero/3;
        int y=zero%3;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=3||ny<0||ny>=3) continue;
            string next=cur;
            swap(next[x*3+y],next[nx*3+ny]);
            if(visited.find(next)==visited.end()){
                visited.insert(next);
                q.push({next,time+1});
            }
        }
    }
    return -1;
}
int main(){
    endstr="123456780";
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int a;
            cin>>a;
            char c=a+'0';
            start+=c;
        }
    }
    int ans=bfs();
    cout<<ans;
}