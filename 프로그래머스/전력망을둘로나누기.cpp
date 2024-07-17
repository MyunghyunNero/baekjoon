#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[101];
int ans[101];
void init() {
    for(int i=0;i<101;i++) {
        arr[i]=i;
        ans[i]=0;
    }
}
int find(int x) {
    if(x==arr[x]) {
        return x;
    }
    return arr[x] = find(arr[x]);
}
void unionX(int x, int y) {
    int u = find(x);
    int n = find(y);
    if( u==n) return;
    arr[u]=n;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    sort(wires.begin(),wires.end());
    for(int i = 0;i<wires.size();i++) {
        init();
        for(int j=0;j<wires.size();j++) {
            if(i==j) continue;
            unionX(wires[j][0],wires[j][1]);
        }
        int cnt=0;
        int diff=0;
        for(int k=1;k<=n;k++){
            find(k);
        }
        for(int k=1;k<=n;k++){
            ans[arr[k]]++;
        }
        for(int k=0;k<101;k++){
            if(ans[k]>0) {
                cnt++;
                diff = abs(diff-ans[k]);
            }
        }
        if(answer>diff){
            answer=diff;
        }
    }
    
    return answer;
}