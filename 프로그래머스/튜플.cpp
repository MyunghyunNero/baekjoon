#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
bool cmp(string a,string b) {
    if(a.size()<b.size()){
        return true;
    }else{
        return false;
    }
}

vector<string> v;
vector<int> answer;
set<int> st;
void splitInt(string str, char delimeter) {
    string token;
    stringstream ss(str);
    while(getline(ss,token,delimeter)) {
        int t = stoi(token);
        if(st.find(t) == st.end()){
            answer.push_back(t);
            st.insert(stoi(token));
        }
    }
}

vector<int> solution(string s) {

    string temp = s.substr(1,s.size()-2);
    string splits = "";
    for(char c : temp) {
        splits+=c;
        if(c == '}') {
            if(splits[0]==','){
                splits = splits.substr(1,splits.size()-1);
            }
            v.push_back(splits);
            splits = "";
        }
        
    }
    sort(v.begin(),v.end(),cmp);
    for(string str : v) {
        string temp = str.substr(1,str.size()-2);
        splitInt(temp,',');
    }
    return answer;
}