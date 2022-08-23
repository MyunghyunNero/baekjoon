#include <iostream>
using namespace std;
pair<int,int> arr[20];
int ans;
int n;
void search(int t,int money){
    if(t==n+1){
        if(money>ans){
            ans=money;
    }
    }
    if(t>n) return;
    if(money>ans){
        ans=money;
    }
    search(t+arr[t].first,money+arr[t].second); //t를 선택
    search(t+1,money); //t선택안하므로 다음
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>> arr[i].first >>arr[i].second;
    }
    search(1,0);
    cout<<ans;
}