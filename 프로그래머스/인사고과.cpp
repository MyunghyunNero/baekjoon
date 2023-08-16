#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    if(a[0]>b[0]){
        return true;
    }else if(a[0]==b[0]){
        if(a[1]>b[1]){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> wanho=scores[0];
    sort(scores.begin(),scores.end(),cmp);
    vector<vector<int>> incept;
    pair<int,int> rights={scores[0][0],scores[0][1]};
    for(int i=0;i<scores.size();i++){
        if(rights.first==scores[i][0]){
            incept.push_back(scores[i]);
    
        }else{
            pair<int,int> temp={scores[i][0],scores[i][1]};
            while(i<scores.size() && scores[i][0]==temp.first){
                if(rights.second>scores[i][1]){
                    if(scores[i][0]==wanho[0] && scores[i][1]==wanho[1]){
                        return -1;
                    }
                }else{
                    incept.push_back(scores[i]);
                    
                }
                i++;
            }
            if(temp.second>rights.second){
                rights=temp;
            }
            i--;
        }
    }
    int wscore= wanho[0]+wanho[1];
    vector<int> pincept;
    for(int i=0;i<incept.size();i++){
        pincept.push_back(incept[i][0]+incept[i][1]);
    }
    sort(pincept.begin(),pincept.end(),greater<>());
    int pre=-1;
    for(int i=0;i<pincept.size();i++){
        if(pre!=pincept[i]){
            answer=i+1;
        }
        pre=pincept[i];
        if(pincept[i]==wscore) break;
    }
    return answer;
    
}