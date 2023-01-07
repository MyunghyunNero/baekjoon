#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,a,b,c;
    int price=0;
    int kac=0;
    cin>>n>>a>>b>>c;
    vector<int> v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end(),greater<int>());
    price += a;
    kac += c;
    int ans = (int)kac/price;
    for(int i = 0;i<n;i++){
        price += b;
        kac += v[i];
        ans = max(ans,(int)kac/price);
    }
    cout<<ans;

}