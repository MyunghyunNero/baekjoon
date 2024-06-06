#include <string>
#include <vector>
using namespace std;
bool check[51];
vector<string> words;
int answer =987654321;
void dfs(string s, string target, int num) {
    if(s==target) {
        answer = min(answer,num);
        return;
    }
    for(int i = 0 ; i<words.size();i++) {
        int cnt = 0;
        if(!check[i]){
            for(int j = 0;j<words[i].size();j++) {
                if(s[j] != words[i][j]){
                    cnt++;
                }
            }
            if(cnt==1){
                check[i]=true;
                dfs(words[i],target,num+1);
                check[i]=false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> word) {
    words=word;
    dfs(begin,target,0);
    if(answer == 987654321){
        answer = 0;
    }
    return answer;
}