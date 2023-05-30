#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
string s;
int t;
string ans="";
int len;
void bfs(string temp){
    queue<string> q;
    q.push(temp);
    int curk=0;
    while(!q.empty() && curk<t){
        int qsize=q.size();
        set<string> visit;
        for(int i=0;i<qsize;i++){
            string curs=q.front();
            q.pop();
            for(int j=0;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                	if (j == 0 && curs[k] == '0') continue;
                    char tmp=curs[j];
                    curs[j]=curs[k];
                    curs[k]=tmp;
                    if(visit.find(curs)==visit.end()){
                        if(curk==t-1 && ans<curs){
                            ans=curs;
                        }
                        q.push(curs);
                        visit.insert(curs);
                    }
                    curs[k]=curs[j];
                    curs[j]=tmp;
                }
            }
        }
        curk++; 
    }
}
int main(){
    cin>>s>>t;
    len=s.length();
    bfs(s);
    
    if(!ans.empty()){
        cout<<ans;
    }else{
        cout<<-1;
    }
}
