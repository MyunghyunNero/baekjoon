#include <iostream>
#include <deque>
using namespace std;
int n,m,cnt;
int index;
int main(){
    cin>>n>>m;
    deque<int> dq;
    for(int i=0;i<n;i++){
        dq.push_back(i+1);
    }
    while(m--){
        int num;
        cin>>num;
        int len=dq.size();
        for(int i=0;i<len;i++){
            if(dq[i]==num){
                index=i;
                break;
            }
        }
        if(index<len-index){
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout<<cnt;

}