#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v;
int sum;
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    if(n>=2){
        while(q.size()!=1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            v.push_back(a+b);
            q.push(a+b);
        }
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        cout<<sum;
    }else{
        cout<<0;
    }
}