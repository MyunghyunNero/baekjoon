#include <iostream>
#include <vector>
using namespace std;
int n,m;
long long cnt[1001];
long long ans,sum;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        sum+=a;    //누적합에서 m을 나눈값 
        cnt[sum%m]++;           //개수 늘리기
    }
    for(int i=0;i<=m;i++){
        ans+=(cnt[i]*(cnt[i]-1))/2;
    }
    cout<<ans+cnt[0];

}