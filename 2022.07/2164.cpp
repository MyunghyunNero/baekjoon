#include <iostream>
#include <queue>
using namespace std;
int n,ans;
queue<int> q;
int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    for(int i=1;i<=2*n;i++){
        if(q.size()==1){
            ans=q.front();
            break;
        }
        if(q.empty()){
            break;
        }
        if(i%2==1){
            q.pop();
        }
        if(i%2==0){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        ans=q.front();
    }
    cout<<ans;
}