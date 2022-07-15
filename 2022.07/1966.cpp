#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t;
int cnt;
int main(){
    cin >>t;
    while(t--){
        int n,m;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int imp;
            cin>>imp;
            q.push({i,imp});
            pq.push(imp);
        }
        cnt=0;
        while(!q.empty()){
            int v=q.front().first;
            int tempimp=q.front().second;
            q.pop();
            if(pq.top()==tempimp){
                pq.pop();
                cnt++;
                if(v==m){
                    cout<<cnt<<'\n';
                    break;
                }
            }else{
                q.push({v,tempimp});
            }
        }
    }

}