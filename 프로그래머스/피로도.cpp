#include <string>
#include <vector>

using namespace std;
vector<vector<int>> dungeon;
int sizearr;
int ans;
int total;
bool check[10];
void dfs(int sum,int cnt){
    ans=max(ans,cnt);
    bool clear=true;
    for(int i=0;i<sizearr;i++){
        if(!check[i] && sum>=dungeon[i][0]){
            check[i]=true;
            dfs(sum-dungeon[i][1],cnt+1);
            check[i]=false;
        }
    }
    
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dungeon= dungeons;
    sizearr=dungeons.size();
    total=k;
    dfs(k,0);
    return ans;
}