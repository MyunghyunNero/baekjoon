#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,s,p;
vector<int> v;
int cnt;
int main(){
    cin>>n>>s>>p;   
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        if(a>s){
            cnt=i+1;
        }
    }
    if(cnt+1==n&&s==v[n-1]){
        cout<<-1;
        return 0;
    }
    if(cnt==n&&s<v[n-1]){
        cout<<-1;
        return 0;
    }
    cout<<cnt+1;


}