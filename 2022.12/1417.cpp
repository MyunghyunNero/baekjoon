#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,less<int>> q;
    int one;
    cin>> one;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    int ans=0;
    while(!q.empty() && q.top()>one){
        int M= q.top();
        q.pop();
        M--;
        one++;
        q.push(M);
        ans++;
    }
    cout <<ans;
    

}