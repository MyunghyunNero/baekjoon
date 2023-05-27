#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string ans;
int cnt;
vector<string> v;
int dp[51];
void change(int start,int end,string str){
    string temp=str;
    sort(temp.begin(),temp.end());
    for(int i=0;i<v.size();i++){
        string temp1=v[i];
        sort(temp1.begin(),temp1.end());
        if(temp!=temp1) continue;
        else{
            int cost=0;
       
            for(int j=0;j<v[i].size();j++){
                if(ans[start+j]!=v[i][j]) cost++;
            }
            dp[start+end-1]=min(dp[start+end-1],dp[start-1]+cost);
        }
    }
}
int main(){
    string str;
    cin>>str;
    ans=" "+str;
    cin>>n;
    for(int i=1;i<=51;i++){
        dp[i]=9e8;
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int len = ans.length();
    for(int i=1;i<=len;i++){
       for(int j=1;j<len-i+1;j++){
            string temp=ans.substr(i,j);
            change(i,j,temp);
       }
    }

    if(dp[len-1]==9e8){
        cout<<-1;
    }else{
        cout<<dp[len-1];
    }

}