#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
vector<string> answer;
stack<pair<string,int>> stk;
bool cmp(vector<string> a,vector<string> b){
    if(a[1]<b[1]){
        return true;
    }else{
        return false;
    }
}
int change(string s){
    int hour=stoi(s.substr(0,s.find(':')));
    int minute=stoi(s.substr(s.find(':')+1));
    return 60*hour+minute; 
}
void startgame(vector<vector<string>> plan){
    int wait=0;
    vector<pair<string,int>> v;
    int time=change(plan[0][1]);
    int play=stoi(plan[0][2]);
    for(int i=1;i<plan.size();i++){
        int curtime=change(plan[i][1]);
        if(time+play>curtime){
            stk.push({plan[i-1][0],(time+play)-curtime});
            time=curtime;
            play=stoi(plan[i][2]);
        }else if(time+play<curtime){
            answer.push_back(plan[i-1][0]);
            while(!stk.empty()){
                string name=stk.top().first;
                time=time+play;
                play=stk.top().second;
                stk.pop();
                if(time+play<=curtime){
                    answer.push_back(name);
                }else{
                    stk.push({name,time+play-curtime});
                    break;
                }
            }
            time=curtime;
            play=stoi(plan[i][2]);
        }else{
            answer.push_back(plan[i-1][0]);
            time=curtime;
            play=stoi(plan[i][2]);
        }
    }
    answer.push_back(plan[plan.size()-1][0]);
    while(!stk.empty()){
        string name=stk.top().first;
        answer.push_back(name);
        stk.pop();
    }
}
vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(),plans.end(),cmp);
    startgame(plans);
    return answer;
}