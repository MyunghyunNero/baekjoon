#include <string>
#include <vector>

using namespace std;
vector<int> arr[1000001];
int inArr[1000001];
int outArr[1000001];
bool isLine(int node){
    if(inArr[node] >= 1 && outArr[node] == 0)
        return true;
    return false;
}
bool isEight(int node) {
    if(inArr[node]>=2 && outArr[node]==2) {
        return true;
    }else{
        return false;
    }
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.assign(4,0);
    int maxNode = 0;
    for(vector<int> edge : edges) {
        inArr[edge[1]]++;
        outArr[edge[0]]++;
        arr[edge[0]].push_back(edge[1]);
        maxNode = max(maxNode,max(edge[0],edge[1]));
    }
    int startNode = 0;
    for(int i=1;i<=maxNode;i++) {
        if(inArr[i]==0 && outArr[i]>=2) {
            startNode = i;
        }
    }
    answer[0]=startNode;
    for(int i=1;i<=maxNode;i++) {
        if(isLine(i)) {
            answer[2]++;
        }else if(isEight(i)) {
            answer[3]++;
        }
    }
    answer[1] = arr[startNode].size()-(answer[2]+answer[3]);
    return answer;
}