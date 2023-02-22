#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    q.push(v[0].second);
    for(int i=1;i<n;i++){
        int start=v[i].first;
        if(start>=q.top()){
            q.pop();
            q.push(v[i].second);
        }else{
            q.push(v[i].second);
        }
    }
    cout<<q.size();
}
