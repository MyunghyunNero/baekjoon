#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;
int n;
int ans;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ans;
        if(ans==0){
            if(q.empty()){
                cout << 0 <<'\n';
            }else{
                cout << q.top()<<'\n';
                q.pop();
            }
        }else{
            q.push(ans);
        }
    }
}