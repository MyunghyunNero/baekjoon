#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t;
int main(){
    cin>>t;
    while(t--){
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        int n;
        long long sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            pq.push(a);
        }
        while(pq.size()!=1){
            long long a,b;
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            sum+=(a+b);
            pq.push(a+b);
        }
        cout<<sum<<'\n';
    }
}