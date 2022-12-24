#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    priority_queue<long long,vector<long long>,greater<long long>> q;
    long long n,m;
    cin >>n>>m;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        q.push(a);
    }
    for(long long i=0;i<m;i++){
        long long a = q.top();
        q.pop();
        long long b=q.top();
        q.pop();
        q.push(a+b);
        q.push(a+b);
    }
    long long ans=0;
    for(long long i=0;i<n;i++){
        ans+=q.top();
        q.pop();
    }
    cout<<ans;
}