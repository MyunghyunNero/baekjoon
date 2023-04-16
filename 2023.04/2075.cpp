#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int,vector<int>,greater<int>> pq;
    cin>>n;
    int temp;
    for(int i=0;i<n*n;i++){
        cin>>temp;
        pq.push(temp);
        if(pq.size()>n) pq.pop();
    }
    cout<<pq.top();
}