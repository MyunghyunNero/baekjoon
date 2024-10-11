#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string str : s) {
        string tmp = "";
        
        int cnt = 0;
        for(int i=0;i<str.size();i++) {
            tmp +=str[i];
            if(tmp.size()>=3) {
                if(tmp.substr(tmp.length()-3,3)=="110") {
                    cnt++;
                    tmp.erase(tmp.length()-3,3);
                }
            }
        }
        int lastIndex = -1;
        for(int i=0;i<tmp.size();i++) {
            if(tmp[i]=='0') {
                lastIndex = i;
            }
        }
        string ans ="";
        if(lastIndex == -1) {
            while(cnt--) {
                ans += "110";
            }
            ans+=tmp;
        }else {
            for(int i=0;i<tmp.size();i++) {
                ans+=tmp[i];
                if(lastIndex == i) {
                    while(cnt--){
                        ans+="110";
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}