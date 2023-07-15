#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d,n;
vector<int> v;
vector<int> pizza;
int ans=0;
int main(){
    cin>>d>>n;
    int cnt=0;
    for(int i=0;i<d;i++){
        int a;
        cin>>a;
        v.push_back(a);
        if(i>0 && v[i-1]< v[i]) v[i]=v[i-1];
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pizza.push_back(a);
    }

    for(int i=d-1;i>=0;i--){
        if(pizza[cnt]<=v[i]){
            ans=i+1;
            cnt++;
        }
        if(cnt==n) break;
    }
    if(cnt==n){
        cout<<ans;
    }else{
        cout<<0;
    }

}