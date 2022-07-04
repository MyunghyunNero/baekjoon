#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int> v;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >>n>>k;
    v.push_back(0);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(v[i-1]+a);
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<'\n';
    }
}