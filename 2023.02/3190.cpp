#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int n,k,l;
int arr[101][101];
int ans;
int direct;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
deque<pair<int,int>> q;
vector<pair<int,char>> v;
int turnDirection( char c)
{
    if (c == 'L')
    {
        if (direct == 0) return 3;   //0은 동
        else if (direct == 1) return 0; //1은 남
        else if (direct == 2) return 1;  //2은 서
        else if (direct == 3) return 2;   //3은 북
    }
    else if (c == 'D')
    {
        if (direct == 0) return 1;
        else if (direct == 1) return 2;
        else if (direct == 2) return 3;
        else if (direct == 3) return 0;
    }
}
void moveSnake(){
    int idx=0;
    while (1)
    {
        ans++;
        int frontx= q.front().first;
        int fronty=q.front().second;
        int backx=q.back().first;
        int backy=q.back().second;
        int nx=frontx+dx[direct];
        int ny=fronty+dy[direct];
        if(nx>n || nx<1 || ny>n || ny<1 || arr[nx][ny]==1){
            break; 
        }
        if(arr[nx][ny]==2){
            q.push_front({nx,ny});
            arr[nx][ny]=1;
        }else{
            q.push_front({nx,ny});
            arr[nx][ny]=1;
            q.pop_back();
            arr[backx][backy]=0;
        }
        if (idx < v.size())
        {
            if (ans == v[idx].first)
            {
                if (v[idx].second == 'L') direct = turnDirection('L');
                else if (v[idx].second == 'D') direct = turnDirection('D');
                idx++;
            }
        }
    }
}
int main(){
    cin>>n;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        arr[a][b]=2;
    }
    q.push_front({1,1});
    arr[1][1]=1;
    cin>>l;
    while(l--){
        int t;
        char k;
        cin>>t>>k;
        v.push_back({t,k});
    }
    moveSnake();
    cout<<ans;
}