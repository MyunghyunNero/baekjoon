#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 8
using namespace std;

bool visited[MAX];
vector<int> v;
int answer ;
void check(vector<int> weak, vector<int> dist, int n) {
    //시작점 변하게
    for(int i=0;i<weak.size()-1;i++) {
        int weakIndex = 0;
        int cnt = 0;
        bool success = false;
        for(int j=0;(j<dist.size()) && (j+1<answer) && (success == false);j++) {
            int end = weak[weakIndex] + dist[v[j]];
            while(end>=weak[weakIndex]) {
                weakIndex++;
                if(weakIndex == weak.size()) {
                    cnt=j+1;
                    success=true;
                    break;
                }
            }
        }
        if(success) answer = min(answer,cnt);
        int start = weak[0];
        for(int i=0;i<weak.size()-1;i++) weak[i]=weak[i+1];
        weak[weak.size()-1]=start+n;
    }
}
void dfs(vector<int> weak, vector<int> dist,int cnt, int n) {
    if(cnt == dist.size()) {
        check(weak,dist,n);
        return;
    }
    for(int i=0;i<dist.size();i++) {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(weak,dist,cnt+1,n);
        v.pop_back();
        visited[i] =false;
    }
}
int solution(int n, vector<int> weak, vector<int> dist) {
    answer = 2e9;
    int weakCnt = weak.size();
    int distCnt = dist.size();
    sort(dist.begin(),dist.end(),greater<>());
    vector<int> tmp = weak;
    for(int i=0;i<tmp.size()-1;i++) {
        int start = tmp[0];
        int end = tmp[weakCnt-1];
        if(end - start <= dist[0]) return 1;
        for(int j=0;j<weakCnt-1;j++) {
            tmp[j]=tmp[j+1];
        }
        tmp[weakCnt-1] = start+n;
    }
    dfs(weak,dist,0,n);
    if(answer == 2e9) answer =-1;
    return answer;
}