#include <iostream>
#include <vector>
using namespace std;
int n,ans;
vector<int> l;
vector<int> r(100001);
vector<int> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        l.push_back(sum);
    }
    sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=v[i];
        r[i]=sum;
    }
    int beehouse=n-1;
    int bee1=0;
    int bee2=0;
    for(int i=1;i<n-1;i++){
        bee2=i;
        int value=2*sum-l[bee1]-l[bee2]-v[bee2];
        ans=max(value,ans);
    }
    beehouse=0;
    bee1=n-1;
    for(int i=n-2;i>=1;i--){
        bee2=i;
        int value=2*sum-r[bee1]-r[bee2]-v[bee2];
        ans=max(value,ans);
    }
    bee1=0;
    bee2=n-1;
    for(int i=1;i<n-1;i++){
        beehouse=i;
        int value=sum-v[bee1]-v[bee2]+v[beehouse];
        ans=max(value,ans);
    }
    cout<<ans;

}