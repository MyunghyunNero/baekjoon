#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int num=1;
    for(int i=0;i<order.size();i++){
        if(num<order[i]){
            for(int j=num;j<order[i];j++){
                s.push(j);
                num++;
            }
            num++;
            answer++;
        }else if(num==order[i]){
            num++;
            answer++;
        }else{
            if(!s.empty()){
                if(s.top()==order[i]){
                    s.pop();
                    answer++;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    return answer;
}