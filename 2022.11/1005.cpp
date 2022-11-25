#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int t;
int n,k;
vector<int> back;

int main(){
    cin>>t;
    while(t--){
        int end;
        cin>>n>>k;
        vector<int> ans(n+1);
        vector<int> pre(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=0;
            pre[i]=false;
        }
        vector<int> d(n+1);
        vector<int> order[n+1];
        vector<int> back;
        queue<int> q;
        for(int i = 1 ;i <=n;i++){
            cin>>d[i];
        }
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            order[x].push_back(y);
            pre[y]++;
        }
        cin>>end;
        for(int i=1;i<=n;i++){
            if(pre[i]==0){
                q.push(i);
            }
            ans[i]=d[i];
        }
    
        while(!q.empty()){
            int start = q.front();
            q.pop();
            for(int i=0;i<order[start].size();i++){
                int next = order[start][i];
                pre[next]--;
                ans[next]= max(ans[next],ans[start]+d[next]);
                if(pre[next]==0) q.push(next);
            }
        }
        cout << ans[end]<<'\n';
    }


}            