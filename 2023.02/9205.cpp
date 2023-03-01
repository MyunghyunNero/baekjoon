#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,t;
bool visited[101];
pair<int,int> start;
pair<int,int> goal;
vector<pair<int,int>> store;
bool bfs(){
    queue<pair<int,int>> q;
    q.push(start);
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(abs(x-goal.first)+abs(y-goal.second)<=1000) return true;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int d=abs(x-store[i].first)+abs(y-store[i].second);
            if(d<=1000){
                visited[i]=true;
                q.push({store[i].first,store[i].second});
            }
        }
    }
    return false;
}
int main(){
    cin>>t;
    while(t--){
        store.clear();
        memset(visited,false,sizeof(visited));
        cin>>n;
        int a,b;
        cin>> a>>b;
        start={a,b};
        for(int i=0;i<n;i++){
            int c,d;
            cin>>c>>d;
            store.push_back({c,d});
        }
        cin>>a>>b;
        goal={a,b};
        if(bfs()){
            cout<<"happy"<<'\n';
        }else{
            cout<<"sad"<<"\n";
        }
    }
}