#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n,s;
vector<int> v;
map<int,int> m;
int minindex;
long long ans;
void checkleftv(int sum,int idx){
    if(idx==n/2){
        m[sum]++;
        return;
    }
    checkleftv(sum+v[idx],idx+1);
    checkleftv(sum,idx+1);
}
void checkrightv(int sum,int idx){
    if(idx==n){
        ans+=m[s-sum];
        return;
    }
    checkrightv(sum+v[idx],idx+1);
    checkrightv(sum,idx+1);
}
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    checkleftv(0,0);
    checkrightv(0,n/2);
    if(s==0){
        cout<<ans-1;
    }else{
        cout<<ans;
    }
}