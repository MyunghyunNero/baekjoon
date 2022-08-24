#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans;
vector<int> a;
vector<int> b;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b.push_back(c);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        ans+=(a[i]*b[n-i-1]);
    }
    cout <<ans;
}