#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set<string> st;
set<string> check;
bool visit[9];
int column;
int row;
int answer;
vector<vector<string>> relations;
bool checkCandi(string a, string b) {
    int aIdx = 0;
    for(int i=0;i<b.size();i++) {
        if(b[i]==a[aIdx]) aIdx++;
    }
    if(aIdx == a.size()) return true;
    return false;
}
void dfs(int cnt, int maxCnt){
    if(cnt == maxCnt) {
        // 유일한지 체크
        bool uniq = true;
        check.clear();
        for(int i=0;i<row;i++) {
            string tmp = "";
            for(int j=0;j<column;j++) {
                if(visit[j]) tmp+=relations[i][j];
            }
            if(check.find(tmp) == check.end()) check.insert(tmp);
            else uniq = false;
        }
        if(!uniq) return;
        
        // 최소성 체크 
        string tmp = "";
        bool minq = true;
        for(int i=0;i<column;i++) {
            if(visit[i]) tmp+=i+'0';
        }
        for(auto iter = st.begin();iter != st.end();iter++) {
            if(checkCandi(*iter,tmp)) minq=false;
        }
        if(minq) {
            st.insert(tmp);
            answer++;
        }
        
    }
    for(int j=0;j<column;j++) {
        if(!visit[j]) {
            visit[j] = true;
            dfs(cnt+1,maxCnt);
            visit[j] = false;
        }
    }
}
int solution(vector<vector<string>> relation) {

    column = relation[0].size();
    row = relation.size();
    relations = relation;
    for(int i=1;i<=column;i++) {  // 조건 갯수
        dfs(0,i);
    }
    return answer;
}