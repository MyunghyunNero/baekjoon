#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int start,des;
pair<int,int> arr[100001];
queue<pair<int,int>> q;
int main(){
    cin>>start>>des;
    q.push({start,0});
    while(!q.empty()){
        int s=q.front().first;
        int d=q.front().second;
        q.pop();
        if(s==des) break;
        if(s-1>=0){
            if(arr[s-1].second==0 && (s-1)!=start) {
                arr[s-1]={s,d+1};
                q.push({s-1,d+1});
            }else if(arr[s-1].second>d+1){
                arr[s-1]={s,d+1};
                q.push({s-1,d+1});
            }
        }
        if(s+1<=100000){
            if(arr[s+1].second==0 && (s+1)!=start){
                arr[s+1]={s,d+1};
                q.push({s+1,d+1});
            }else if(arr[s+1].second>d+1){
                arr[s+1]={s,d+1};
                q.push({s+1,d+1});
            }
        }
        if(s*2<=100000){
            if(arr[s*2].second==0 && (s*2)!=start){
                arr[s*2]={s,d+1};
                q.push({2*s,d+1});
            }else if(arr[s*2].second>d+1){
                arr[s*2]={s,d+1};
                q.push({2*s,d+1});
            }
        }
    }
    int backtrack=des;
    vector<int> v;
    while(backtrack!=start){
        v.push_back(backtrack);
        backtrack=arr[backtrack].first;
    }
    v.push_back(start);
    cout<<arr[des].second<<'\n';
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<' ';
    }

}