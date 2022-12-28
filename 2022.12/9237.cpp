#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>);
    int len =v.size()-1;
    int maxValue=-1;
    for(int i=0;i<n;i++){
        maxValue = max(v[i]-len+i,maxValue);
    }
    cout<< maxValue+len+2;
}