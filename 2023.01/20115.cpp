#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<double> v;
    for(int i=0;i<n;i++){
        double a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<double>());
    double ans = v[0];
    for(int i=1;i<n;i++){
        ans +=v[i]/2;
    }
    cout<<ans;
}