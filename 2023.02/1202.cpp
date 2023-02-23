#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int,int>> v;
vector<int> c;
priority_queue<int> pq;
int n,k;
long long sum;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        c.push_back(a);
    }
    sort(v.begin(),v.end());
    sort(c.begin(),c.end());
    int idx=0;
    for(int i=0;i<k;i++){
        while(idx<n&&c[i]>=v[idx].first){
            pq.push(v[idx].second);
            idx++;
        }
        if(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
    }
    cout<<sum;

}
