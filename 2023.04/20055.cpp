#include <iostream>
#include <deque>
using namespace std;
deque<pair<int,int>> dq; //first -> 내구도 ,second 로봇 올라간 순서
int n,k;
void spin(){
    pair<int,int> tmp = dq.back();
    dq.pop_back();
    dq.push_front(tmp);
}
void checkFront(int idx){

    if(dq[idx+1].first>0 && dq[idx+1].second==0 && idx<n-1){
        pair<int,int> tmp=dq[idx];
        dq[idx+1].first--;
        dq[idx+1].second=tmp.second;
        dq[idx].second=0;
    }
}
bool checkK(){
    int cnt=0;
    for(int i=0;i<dq.size();i++){
        if(dq[i].first==0){
            cnt++;
        }
    }
    if(cnt>=k){
        return true;
    }else{
        return false;
    }
}
int ans=0;
int main(){
    cin>>n>>k;
    for(int i=0;i<2*n;i++){
        int a;
        cin>>a;
        dq.push_back({a,0});
    }
    int robot=1;
    while(1){
        if(checkK()) break;
        spin();
        if(dq[n-1].second>0){
            dq[n-1].second=0;
        }
        for(int i=n-2;i>=0;i--){
        	if(dq[i].second>0)
            	checkFront(i);
        }
        if(dq[n-1].second>0){
            dq[n-1].second=0;
        }
        if(dq[0].first>0){
            dq[0].second=robot++;
            dq[0].first--;
        }
        
        ans++;
    }
    cout<<ans;
}