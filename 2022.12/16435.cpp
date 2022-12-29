#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        if(l>=v[i]) l=l+1;
    }
    cout<<l;
}