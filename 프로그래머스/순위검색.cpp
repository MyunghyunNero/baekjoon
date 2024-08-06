#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
map<string,vector<int>> m;
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
vector<string> split2(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        if(buffer == "and") continue;
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}
bool visit[50001];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0;i<info.size();i++) {
        //띄어쓰기로 쪼개기 
        vector<string> tmp = split(info[i],' ');
        string k1,k2,k3,k4;
        for(int j=0;j<2;j++) {
            if(j==0) k1=tmp[0];
            else k1='-';
            for(int k=0;k<2;k++) {
                if(k==0) k2=tmp[1];
                else k2='-';
                for(int l=0;l<2;l++) {
                    if(l==0) k3=tmp[2];
                    else k3='-';
                    for(int p=0;p<2;p++) {
                        if(p==0) k4=tmp[3];
                        else k4='-';
                        m[k1+k2+k3+k4].push_back(stoi(tmp[4]));
                    }
                }
            }
        }
    }
    for(auto iter = m.begin(); iter!=m.end();iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
    for(string s : query) {
        vector<string> tmp = split2(s, ' ');
        int cnt = 0;
        string key = tmp[0]+tmp[1]+tmp[2]+tmp[3];
        vector<int> scores = m[key];
        
        int idx = lower_bound(scores.begin(), scores.end(), stoi(tmp[4])) - scores.begin();
        
        answer.push_back(scores.size()-idx);
    }
    return answer;
}