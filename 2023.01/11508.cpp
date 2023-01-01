#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cin >>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        v.push_back(c);
        sum+=c;
    }
    sort(v.begin(),v.end(),greater<>());
    int cnt = n/3;
    int index=2;
    for(int i=0;i<cnt;i++){
        sum-=v[index];
        index+=3;
    }
    cout<<sum;
}