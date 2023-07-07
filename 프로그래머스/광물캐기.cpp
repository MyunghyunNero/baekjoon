#include <string>
#include <vector>
#include <set>
using namespace std;
vector<string> mineral;
int ans=987654321;
int len;
void dfs(vector<int> pick,vector<int> select){
    if(select.size()==len){
        int sum=0;
        for(int i=0;i<len;i++){
            for(int j=i*5;j<i*5+5;j++){
                if(j>=mineral.size()) break;
                if(select[i]==0){
                    sum+=1;
                }else if(select[i]==1){
                    if(mineral[j]=="diamond"){
                        sum+=5;
                    }else{
                        sum+=1;
                    }
                }else{
                    if(mineral[j]=="diamond"){
                        sum+=25;
                    }else if(mineral[j]=="iron"){
                        sum+=5;
                    }else{
                        sum+=1;
                    }
                }
            }
        }
        ans=min(sum,ans);
    }
    for(int i=0;i<3;i++){
        if(pick[i]){
            pick[i]--;
            select.push_back(i);
            dfs(pick,select);
            pick[i]++;
            select.erase(select.begin()+select.size()-1);
        }
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    int sum=0;
    for(int i=0;i<picks.size();i++){
        sum+=picks[i];
    }
    int minsize=minerals.size();
    len=min(sum,minsize%5==0?minsize/5:minsize/5+1);
    mineral=minerals;
    vector<int> sel;
    dfs(picks,sel);
    return ans;
}