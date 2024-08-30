#include <string>
#include <vector>

using namespace std;
vector<int> win[101];
vector<int> lose[101];
bool visited[101];
void init() {
    for(int i=0;i<101;i++) {
        visited[i] = false;
    }
}
int winDfs(int start) {
    int sum = 1;
    for(int i = 0;i<win[start].size();i++) {
        int next= win[start][i];
        if(!visited[next]) {
            visited[next] = true;
            sum += winDfs(next);
        }
    }
    return sum;
}
int loseDfs(int start) {
    int sum = 1;
    for(int i = 0;i<lose[start].size();i++) {
        int next= lose[start][i];
        if(!visited[next]) {
            visited[next] = true;
            sum += loseDfs(next);
        }
    }
    return sum;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++) {
        int w = results[i][0];
        int l = results[i][1];
        win[w].push_back(l);
        lose[l].push_back(w);
    }
    for(int i=1;i<=n;i++) {
        init();
        visited[i] = true;
        int retWin = winDfs(i);
        int retLose = loseDfs(i);
        if(retWin + retLose - 1 ==n) {
            answer++;
        }
        
    }
    return answer;
}