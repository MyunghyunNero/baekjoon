#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string operation : operations) {
        if(operation == "D 1"){
            if(!dq.empty())
                dq.pop_back();
        }else if(operation == "D -1"){
            if(!dq.empty())
                dq.pop_front();
        }
        else{
            string tmp = operation.substr(2,operation.size()-2);
            int num = stoi(tmp);
            dq.push_back(num);
        }
        sort(dq.begin(),dq.end());
    }
    if(dq.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(dq[dq.size()-1]);
        answer.push_back(dq[0]);
    }
    
    return answer;
}