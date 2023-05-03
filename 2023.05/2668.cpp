#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<int> ans;
int arr[101];
int n;
void cycle(int start){
    set<int> s;
    bool check=false;
    int a=arr[start];
    while(s.find(a)==s.end()){
        s.insert(a);
        if(a==start){
            s.insert(start);
            check=true;
            break;
        }
        a=arr[a];
    }
    if(check){
        for(auto iter=s.begin();iter!=s.end();iter++){
            ans.insert(*iter);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cycle(i);
    }
    cout<<ans.size()<<"\n";
    for(auto o : ans){
        cout<<o<<'\n';
    }
}