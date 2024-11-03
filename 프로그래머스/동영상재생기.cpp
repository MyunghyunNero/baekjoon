#include <string>
#include <vector>

using namespace std;
int changeSecond(string s) {
    int hour = stoi(s.substr(0,2))*60;
    int minute = stoi(s.substr(3,2));
    return hour +minute;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int videoLen = changeSecond(video_len);
    int posTime = changeSecond(pos);
    int opStart = changeSecond(op_start);
    int opEnd = changeSecond(op_end);
    for(string c: commands) {
        if( posTime>=opStart && posTime <= opEnd ) {
            posTime = opEnd;
        }
        if(c =="next") {
            if(posTime + 10 <= videoLen) {
                posTime +=10;
            }else {
                posTime = videoLen;
            }
        }else if(c =="prev") {
            if(posTime - 10 >= 0) {
                posTime -= 10;
            }else {
                posTime = 0;
            }
        }
        if( posTime>=opStart && posTime <= opEnd ) {
            posTime = opEnd;
        }
        
    }
    string hour = to_string(posTime/60);
    if(hour.size()<2) hour = "0"+hour;
    posTime%=60;
    string minute = to_string(posTime);
    if(minute.size()<2) minute = "0" + minute;
    answer = hour + ":" + minute;
    return answer;
}