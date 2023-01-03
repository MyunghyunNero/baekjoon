#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans=0;
    int index=0;
    for(int i=0;i<m;i++){
        if(i+1>n) break;
        int value = v[i]*(i+1);
        if(ans<value) {
            index=v[i];
            ans=value;
            }
    }
    cout << index<< ' ' << ans;
}