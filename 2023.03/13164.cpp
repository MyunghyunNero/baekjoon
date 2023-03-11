#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int sum;
vector<int> v;
int main(){
    cin>>n>>m;
    int prev;
    cin>>prev;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a-prev);
        prev=a;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-m+1;i++){
        sum+=v[i];
    }
    cout<<sum;
}