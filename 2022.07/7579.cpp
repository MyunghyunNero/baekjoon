#include<iostream>
#include<algorithm>
using namespace std;
int n, m,sum;
int memory[101], cost[101];
int dp[101][10001];
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>memory[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        sum+=cost[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j>=cost[i]){
                dp[i][j]=dp[i-1][j-cost[i]]+memory[i];              //여기서 j는 비용을 나타냄 즉 비용을 인덱스로 두고 메모리를 값으로 넣음
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);                     //i번째 앱을 비활성화 할떄 안할떄 비교 후 메모리 큰걸 넣음
        }
    }
    for(int j=0;j<=sum;j++){
        if(dp[n][j]>=m){
            cout << j;
            break;
        }
    }
}