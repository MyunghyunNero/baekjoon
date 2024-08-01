#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr[100001];
bool check[100001];
vector<int> answer;
void checkSource(vector<int> source , int n, int v, int len) {
    for(int i=0;i<len;i++) {
        if(source[i] == n) {
            answer[i] = v;
            break;
        }
    }
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
   
    queue<pair<int,int>> q;
    int len = sources.size();
    for(vector<int> road : roads) {
        arr[road[0]].push_back(road[1]);
        arr[road[1]].push_back(road[0]);
    }
    for(int i = 0;i < sources.size(); i++) {
        answer.push_back(-1);
    }
    q.push({destination,0});
    check[destination] = true;
    checkSource(sources,destination,0,len);
    while(!q.empty()) {
        int x = q.front().first;
        int value = q.front().second;
        q.pop();
        for(int i=0;i<arr[x].size();i++) {
            if(!check[arr[x][i]]) {
                check[arr[x][i]] = true;
                q.push({arr[x][i],value+1});
                checkSource(sources,arr[x][i],value+1,len);
            }
        }
    }
    return answer;
}