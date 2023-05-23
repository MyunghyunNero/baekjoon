#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int t;
bool check[10000];
string ans;
void bfs(int start,int end){
    queue<pair<int,string>> q;
    string st="";
    q.push({start,st});
    check[start]=true;
    while(!q.empty()){
        int num=q.front().first;
        string com=q.front().second;
        q.pop();
        if(num==end){
            ans=com;
            break;
        }
        if(!check[(2*num)%10000]){
            check[(2*num)%10000]=true;
            q.push({(2*num)%10000,com+"D"});
        }
        int snum= num-1<0?9999:num-1;
        if(!check[snum]){
            check[snum]=true;
            q.push({snum,com+"S"});
        }
        int temp=num;
        int ltemp=temp/1000+temp%1000 *10;
        if(!check[ltemp]){
            check[ltemp]=true;
            q.push({ltemp,com+"L"});
        }
        int rtemp=temp%10 *1000 + temp/10;
        if(!check[rtemp]){
            check[rtemp]=true;
            q.push({rtemp,com+"R"});
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        memset(check,false,sizeof(check));
        ans="";
        bfs(a,b);
        cout<<ans<<"\n";
    }
}