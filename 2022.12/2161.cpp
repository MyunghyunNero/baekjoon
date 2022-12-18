#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int main(){
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){;
        q.push(i);
    }
    vector<int> discard;
    while(1){
        if(q.size()==1) break;
        int a=q.front();
        q.pop();
        discard.push_back(a);
        if(q.size()==1) break;
        int b=q.front();
        q.pop();
        q.push(b);
    }
    for(int i=0;i<n-1;i++){
        cout << discard[i]<<' ';
    }
    cout << q.front();
}