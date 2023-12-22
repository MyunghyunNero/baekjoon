#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string,int> m;
bool checkStr(string s){
    if(m.find(s) != m.end()){
        return true;
    }
    return false;
}
vector<int> solution(string msg) {
    vector<int> answer;
    int index;
    for(int i=0;i<26;i++){
        char c = (char)('A'+i);
        string s;
        s+=c;
        m[s] = i+1;
        index = i+1;
    }
    for(int i = 0;i<msg.size();i++){
        string prev;
        prev += msg[i];
        for(int j=2;j <= msg.size()-i;j++){
            string cur = msg.substr(i,j);
            if(checkStr(cur)){
                prev = cur;
            }else{
                m[cur] = ++index;
                break;
            }
        }
        i+=prev.size()-1;
        answer.push_back(m[prev]);
    }
    return answer;
}