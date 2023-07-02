#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
map<string,set<string>> m;
map<string,int> sig;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(string s : report){
        string tmp;
        vector<string> str;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str.push_back(tmp);
                tmp="";
            }else{
                tmp+=s[i];
            }
        }
        str.push_back(tmp);
        m[str[0]].insert(str[1]);
    }
    for(int i=0;i<id_list.size();i++){
        for(string s: m[id_list[i]]){
            sig[s]++;
        }
    }
    for(int i=0;i<id_list.size();i++){
        int cnt=0;
        for(string s: m[id_list[i]]){
            if(sig[s]>=k) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}