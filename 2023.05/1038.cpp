#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<long long> v;
void sol(){
    queue<long long> q;
    for(int i=0;i<=9;i++){
        q.push(i);
        v.push_back(i);
    }
    while (!q.empty())
    {
        long long num=q.front();
        int last=num%10;
        q.pop();
        for(int i=0;i<last;i++){
            long long newnum=num*10+i;
            q.push(newnum);
            v.push_back(newnum);
        }
    }
    if(n>=v.size()){
        cout<<-1;
    }else{
        cout<<v[n];
    }

    
}
int main(){
    cin>>n;
    sol();
}