#include <iostream>
using namespace std;
int main(){
    int m,n,k;
    cin >> m>>n>>k;
    int ans=0;
    while(m+n>=k+3 && m>=2 && n>=1){   //세가지 조건 만족시키면서 반복
        ans++;
        m-=2;
        n-=1;
    }
    cout << ans;
}