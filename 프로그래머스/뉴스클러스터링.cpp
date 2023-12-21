#include <string>
#include <iostream>
#include <map>

using namespace std;
map<string,int> m1;
map<string,int> m2;
map<string,int> uni;
map<string,int> inter;
bool checkAlp(string s) {
    bool check = true;
    for(int i = 0 ; i<2;i++) {
        if(!(s[i]>='a'&&s[i]<='z')){
            check = false;
            break;
        }
    }
    return check;
}
int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0;i<str1.size();i++){
        str1[i] = tolower(str1[i]);
    }
    for(int i=0;i<str2.size();i++){
        str2[i] = tolower(str2[i]);
    }
    for(int i=0;i<str1.size()-1;i++){
        string s = str1.substr(i,2);
        if(checkAlp(s)) {
            m1[s]++;
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        string s = str2.substr(i,2);
        if(checkAlp(s)) {
            m2[s]++;
        }
    }
    //inter
    for(auto iter : m1){
        auto m2Iter = m2.find(iter.first);
        if(m2Iter != m2.end()) {
            int minValue = min(iter.second,m2Iter->second);
            inter[iter.first]=minValue;
        }
    }
    //union
    for(auto iter : m1) {
        uni[iter.first] = iter.second;
        auto m2Iter = m2.find(iter.first);
        if(m2Iter != m2.end()) {
            int maxValue = max(iter.second,m2Iter->second);
            uni[iter.first] = maxValue;
        }
    }
    for(auto iter : m2) {
        auto m1Iter = m1.find(iter.first);
        if(m1Iter == m1.end()) {
            uni[iter.first] = iter.second;
        }
    }
    
    int interAnswer = 0;
    int uniAnswer = 0;
    for(auto& iter : inter) {
        interAnswer += iter.second;
    }
    for(auto& iter : uni) {
        uniAnswer += iter.second;
    }
    if(uniAnswer == 0){
        answer =1*65536;
    }else{
        float cal = ((float)interAnswer/uniAnswer)*65536;
        answer= cal;
    }
    return answer;
}