#include <string>
#include <vector>

using namespace std;
int dx[]={10,20,30,40};
pair<int,int> ans;
vector<int> emo;
vector<vector<int>> user;
void dfs(int idx,vector<int> discount){
    if(idx==emo.size()){
        int plus=0;
        int totalsum=0;
        for(int i=0;i<user.size();i++){
            int userrate = user[i][0];
            int usersum = user[i][1];
            int sum=0;
            bool check = false;
            for(int j=0;j<emo.size();j++){
                if(discount[j]>=userrate){
                    sum+=(emo[j]*(100-discount[j])/100);
                }
                if(sum>=usersum){
                    check=true;
                    break;
                }
            }
            if(check){
                plus++;
            }else{
                totalsum+=sum;
            }
        }
        if(ans.first<plus){
            ans={plus,totalsum};
        }else if(ans.first==plus){
            if(ans.second<=totalsum){
                ans={plus,totalsum};
            }
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        discount.push_back(dx[i]);
        dfs(idx+1,discount);
        discount.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    user=users;
    emo=emoticons;
    vector<int> discount;
    dfs(0,discount);
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}