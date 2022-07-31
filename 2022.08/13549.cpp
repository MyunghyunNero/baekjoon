#include <iostream>
#include <queue>
using namespace std;
int n,k;
bool visit[100002];
int ans;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int main(){
    cin>>n>>k;
    q.push({0,n});
    visit[n]=true;
    while(!q.empty()){
        pair<int,int> x=q.top();
        q.pop();
        if(x.second==k){
            ans=x.first;
            break;
        }
        if(x.second*2<=100000&& !visit[x.second*2]){
            q.push({x.first,x.second*2});
            visit[x.second*2]=true;
        }
        if(x.second+1<=100000&& !visit[x.second+1]){
            q.push({x.first+1,x.second+1});
            visit[x.second+1]=true;
        }
        if(x.second-1>=0&& !visit[x.second-1]){
            q.push({x.first+1,x.second-1});
            visit[x.second-1]=true;
        }
    }
    cout <<ans;
}