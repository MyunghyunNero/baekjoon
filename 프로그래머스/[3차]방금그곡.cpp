#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

string changeStr(string s) {
    string tmp = "";
    for(int i =0 ;i<s.size();i++){
        bool check = false;
        if(i<s.size()-1){
            if(s[i]=='C' && s[i+1]=='#'){
                tmp+='H';
                i++;
                check = true;
            }
            if(s[i]=='D' && s[i+1]=='#'){
                tmp+='I';
                i++;
                check = true;
            }
            if(s[i]=='F' && s[i+1]=='#') {
                tmp+='J';
                i++;
                check = true;
            }
            if(s[i]=='G' && s[i+1]=='#'){
                tmp+='K';
                i++;
                check = true;
            }
            if(s[i]=='A' && s[i+1]=='#') {
                tmp+='L';
                i++;
                check = true;
            }
            if(s[i]=='B' && s[i+1]=='#') {
                tmp+='M';
                i++;
                check = true;
            }
        }
        if(!check) {
            tmp +=s[i];
        }
    }
    return tmp;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m = changeStr(m);
    int playTime = 0;
    for(string str : musicinfos) {
        vector<string> info = split(str, ',');
        int startTime = stoi(info[0].substr(0,2)) * 60 + stoi(info[0].substr(3,2));
        int endTime = stoi(info[1].substr(0,2)) * 60 + stoi(info[1].substr(3,2));
        int remainTime = endTime - startTime;
        string infoPlay = changeStr(info[3]);
        int len = infoPlay.size();
        string tmp = "";
        for(int i = 0 ; i < remainTime/len ; i++) {
            tmp += infoPlay;
        }
        tmp += infoPlay.substr(0,remainTime%len);
        if(tmp.find(m) != string::npos) {
            if(playTime < remainTime) {
                playTime = remainTime;
                answer = info[2];
            }
        }
    }
    return answer;
}