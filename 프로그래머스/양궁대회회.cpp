#include <string>
#include <vector>
#include <iostream>

using namespace std;
string anstring="";
vector<int> in;
int ans=0;
int apeach=0;
void dfs(int idx,int cnt,int score,int apechscore,string s){
    if(idx>10){
        if(apechscore<score && ans<score-apechscore){
            if(cnt>0){
                s[10]=(char)(s[10]+cnt);
            }
            ans=score-apechscore;
            anstring=s;
        }else if(!anstring.empty() && ans==score-apechscore &&apechscore<score ){
            for(int i=10;i>=0;i--){
                if(anstring[i]<s[i]){
                    if(cnt>0){
                        s[10]=(char)(s[10]+cnt);
                    }
                    ans=score;
                    anstring=s;
                    break;
                }else if(anstring[i]==s[i]){
                    continue;
                }else{
                    break;
                }
            }
        }
        return;
    }
    if(cnt>in[idx] && in[idx]!=0){
        dfs(idx+1,cnt-(in[idx]+1),score+(10-idx),apechscore-(10-idx),s+to_string(in[idx]+1));
    }else if(cnt>in[idx] && in[idx]==0){
        dfs(idx+1,cnt-(in[idx]+1),score+(10-idx),apechscore,s+to_string(in[idx]+1));
    }
    dfs(idx+1,cnt,score,apechscore,s+to_string(0));
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    for(int i=0;i<info.size();i++){
        in.push_back(info[i]);
        if(info[i]>0){
            apeach+=(10-i);
        }
    }
    dfs(0,n,0,apeach,"");
    for(int i=0;i<anstring.size();i++){
        answer.push_back(anstring[i]-'0');
    }
    if(ans==0){
        answer.push_back(-1);
    }
    return answer;
}