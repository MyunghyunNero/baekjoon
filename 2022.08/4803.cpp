#include <iostream>
#include <vector>
using namespace std;
bool visit[501];
vector<int> tree[501];
int n,m,ans,cnt;
bool dfs(int cur,int post){    //인자 두개인 이유: 양뱡향 노드의 트리이기 떄문에  다시 돌아가는 경우를 제거하기위함
    visit[cur]=true;
    for(int i=0;i<tree[cur].size();i++){
        if(tree[cur][i]==post){
            continue;
        }
        if(visit[tree[cur][i]]){
            return false;
        }
        if(!dfs(tree[cur][i],cur)){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int v,e;
    while(1){
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        cnt++;
        ans=0;
        for (int i = 1; i <= 500; i++)
		{
			tree[i].clear();
			visit[i] = false;
		}
        for (int i = 0; i < m; i++)
		{
			cin >> v >> e;
			tree[e].push_back(v);
			tree[v].push_back(e);
		}
        for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				if (dfs(i, 0)) ans++;
		}
        cout << "Case " << cnt << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees." << '\n';
		else if (ans == 1)
			cout << "There is one tree." << '\n';
		else if (ans == 0)
			cout << "No trees." << '\n';
    }

}