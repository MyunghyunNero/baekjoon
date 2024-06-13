#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,vector<pair<string,bool>>> m;
vector<string> answer;
int len;
void dfs(vector<string> ans, string start) {
    if(ans.size() == len+1 && answer.empty()) {
        answer = ans;
        return;
    } 
    for(int i =0 ;i<m[start].size();i++) {
        pair<string,bool> p = m[start][i];
        if(!p.second) {
            vector<string> tmp = ans;
            tmp.push_back(p.first);
            m[start][i] = {p.first, true};
            dfs(tmp,p.first);
            m[start][i] = {p.first, false};
        }
    }
    
}
vector<string> solution(vector<vector<string>> tickets) {
    len=tickets.size();
    for(vector<string> ticket : tickets) {
        m[ticket[0]].push_back({ticket[1],false});
    }
    for(auto iter = m.begin();iter!=m.end();iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
    vector<string> tmp;
    tmp.push_back("ICN");
    dfs(tmp,"ICN");
    
    return answer;
}