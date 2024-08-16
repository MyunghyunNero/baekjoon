#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
char person[8] = {'A','C','F','J','M','N','R','T'};
bool visit[8];
vector<string> datas;
int cnt;
void dfs(string ans,map<char,vector<string>>& m) {
    if(ans.size()==8) {
        bool check = true;
        for(int i =0;i<8;i++) {
            if(!check) break;
            vector<string> tmp = m[ans[i]];
            for(int j = 0;j<tmp.size();j++) {
                char target = tmp[j][0];
                char comp = tmp[j][1];
                int val = tmp[j][2] - '0';
                if(comp == '=') {
                    bool checktmp = false;
                    if(i-val-1>=0) {
                        if(ans[i-val-1]==target) checktmp = true;
                    }
                    if(i+val+1<8) {
                        if(ans[i+val+1]==target) checktmp = true;
                    }
                    if(!checktmp) {
                        check =false;
                        break;
                    }
                }
                if(comp == '<') {
                    bool checktmp = false;
                    for(int k=1;k<=val;k++) {
                        if(i-k>=0) {
                            if(ans[i-k] == target) checktmp= true;
                        }
                        if(i+k<8) {
                            if(ans[i+k] == target) checktmp= true;
                        }
                    }
                    if(!checktmp) {
                        check =false;
                        break;
                    }
                }
                if(comp == '>') {
                    bool checktmp = true;
                    for(int k=1;k<=val+1;k++) {
                        if(i-k>=0) {
                            if(ans[i-k] == target) checktmp= false;
                        }
                        if(i+k<8) {
                            if(ans[i+k] == target) checktmp= false;
                        }
                    }
                    if(!checktmp) {
                        check =false;
                        break;
                    }
                }
            }
        }
        if(check) {
            cnt++;
        }
    }
    for(int i=0;i<8;i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(ans+person[i],m);
            visit[i] = false;
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    cnt = 0;
    for(int i=0;i<8;i++) {
        visit[i] = false;
    }
    datas = data;
    map<char,vector<string>> m;
    for(string s : data) {
        char start = s[0];
        string tmp = s.substr(2,3);
        m[start].push_back(tmp);
    }
    dfs("",m);
    return cnt;
}