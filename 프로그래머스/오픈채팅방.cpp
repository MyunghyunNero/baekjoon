#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
map<string,string> m;
vector<string> splitStr(string s){
    stringstream ss(s);
    vector<string> split;
    string word;
    while(getline(ss,word,' ')){
        split.push_back(word);
    }
    return split;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(string s : record){
        vector<string> splits = splitStr(s);
        if(splits[0] != "Leave"){
            if(m.find(splits[1]) == m.end()){
                m.insert({splits[1],splits[2]});
            }
            else{
                m[splits[1]] = splits[2];
            }
        }
    }
    for(string s : record) {
        vector<string> splits = splitStr(s);
        string ans="";
        if(splits[0] == "Enter"){
            ans+=m[splits[1]];
            ans+="님이 들어왔습니다.";
        }else if(splits[0] == "Leave"){
            ans+=m[splits[1]];
            ans+="님이 나갔습니다.";
        }else{
            continue;
        }
        answer.push_back(ans);
    }
    return answer;
}