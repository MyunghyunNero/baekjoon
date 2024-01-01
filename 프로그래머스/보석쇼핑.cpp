#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int start =0;
    int head=0;
    int minStart=0;
    int minHead=0;
    int gemSize = gems.size();
    for(int i=0 ;i<gemSize;i++){
        m[gems[i]]++;
        head=i;
        if(m[gems[i]]==1){
            minStart = start;
            minHead = head;
        }else{
            for(int j=start;j<i;j++){
                if(m[gems[j]]>1){
                    m[gems[j]]--;
                }else{
                    start=j;
                    if(minHead-minStart>head-start){
                        minHead=head;
                        minStart=start;
                    }
                    break;
                }
            }
        }
    }
    answer.push_back(minStart+1);
    answer.push_back(minHead+1);
    return answer;
}