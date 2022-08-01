#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2100000000
int n,m;
long long dist[510];
vector<pair<int,int>> arr[510];
bool check;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie();
    cin>>n>>m;
    for (int i = 0; i < m; i++)
	{
        int a,b,c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
    for (int i = 1; i <= n; i++){
		dist[i] = INF; 
    }
    dist[1]=0;
    for(int t=1;t<=n;t++){         //n-1번 실행하면 모든 간선 최단경로 구해짐
        for(int j=1;j<=n;j++){
            for(int i=0;i<arr[j].size();i++){
                int nx=arr[j][i].first;
                int nw=arr[j][i].second;
                if(dist[j]==INF) continue;
                if(dist[nx]>dist[j]+nw){
                    dist[nx]=dist[j]+nw;
                    if(t==n){
                        check=true;           //음의 사이클이 돈다는 증거
                    }
                }
            }
        }
    }
    if (check) cout << -1 << '\n';
	else
	{
		for (int i = 2; i <= n; i++){
            if(dist[i]==INF){
                cout << -1 <<'\n';
            }else{
                cout <<dist[i]<<'\n';
            }
        }
	}
}