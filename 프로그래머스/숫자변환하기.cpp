#include <string>
#include <vector>
#include <queue>
using namespace std;
int arr[1000001];
int x1,y1,n1;
void bfs(){
    queue<int> q;
    q.push(x1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x*3<=y1 && arr[x*3]==0){
            arr[x*3]=arr[x]+1;
            q.push(x*3);
        }
        if(x*2<=y1 && arr[x*2]==0){
            arr[x*2]=arr[x]+1;
            q.push(x*2);
        }
        if(x+n1<=y1 && arr[x+n1]==0){
            arr[x+n1]=arr[x]+1;
            q.push(x+n1);
        }
    }
}
int solution(int x, int y, int n) {
    int answer = 0;
    x1=x;
    y1=y;
    n1=n;
    bfs();
    if(x==y) return 0;
    if(arr[y]==0){
        return -1;
    }
    return arr[y];
}