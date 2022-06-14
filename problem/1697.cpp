#include <iostream>
#include <queue>
using namespace std;
bool check[100001];       //그 위치을 들럿는지 확인
int d[100001];            //위치에 있는 값이 몇번쨰인지 저장
int main(){
    int n,k;
    cin >>n>>k;
    check[n]=true;
    d[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){             //시작점에서 모든위치가 몇번째에 도달하는지 저장
        int now=q.front();
        q.pop();
        if(now-1>=0){                         //지금 위치에서 1을 뺸것
            if(check[now-1]==false){
                q.push(now-1);
                check[now-1]=true;
                d[now-1]=d[now]+1;
            }
        }
        if(now+1<100001){                 //지금 위치에서 1을 더한것
            if(check[now+1]==false){
                q.push(now+1);
                check[now+1]=true;
                d[now+1]=d[now]+1;
            }
        }
        if(now*2<100001){           //지금위치에서 순간이동(2배)
            if(check[now*2]==false){
                q.push(now*2);
                check[now*2]=true;
                d[now*2]=d[now]+1;
            }
        }
    }
    cout<<d[k];
}