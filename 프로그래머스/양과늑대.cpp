#include <string>
#include <vector>

using namespace std;
int ans;
vector<int> graph[18];
vector<int> infor;
void dfs(int start,int sheep,int wolf,vector<int> cango){
    if(!infor[start]) sheep++;
    else wolf++;
    if(sheep<=wolf) return;
    if(ans<sheep){
        ans=sheep;
    }
    for(int i=0;i<cango.size();i++){
        vector<int> next=cango;
        next.erase(next.begin()+i);
        for(int j=0;j<graph[cango[i]].size();j++){
            next.push_back(graph[cango[i]][j]);
        }
        dfs(cango[i],sheep,wolf,next);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i=0;i<info.size();i++){
        infor.push_back(info[i]);
    }
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> next;
    for(int i=0;i<graph[0].size();i++){
        next.push_back(graph[0][i]);
    }
    dfs(0,0,0,next);
    return ans;
}