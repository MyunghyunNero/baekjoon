#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string,vector<string>> m;
int counttime(string a,string b){
    int bidx=b.find(':');
    int bhour=stoi(b.substr(0,bidx));
    int bmin=stoi(b.substr(bidx+1));
    int aidx=a.find(':');
    int ahour=stoi(a.substr(0,aidx));
    int amin=stoi(a.substr(aidx+1));
    int ans=0;
    if(bmin<amin){
        ans=(bhour-1-ahour)*60+(60+bmin-amin);
    }else{
        ans=(bhour-ahour)*60+(bmin-amin);
    }
    return ans;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(string s:records){
        vector<string> str;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str.push_back(tmp);
                tmp="";
            }else{
                tmp+=s[i];
            }
        }
        str.push_back(tmp);
        m[str[1]].push_back(str[0]);
    }
    for(auto it=m.begin();it!=m.end();it++){
        vector<string> tmp=it->second;
        int cnt=0;
        int ans=fees[1];
        if(tmp.size()%2==0){
            for(int i=1;i<tmp.size();i+=2){
                cnt+=counttime(tmp[i-1],tmp[i]);
            }
        }else{
            for(int i=1;i<tmp.size()-1;i+=2){
                cnt+=counttime(tmp[i-1],tmp[i]);
            }
            cnt+=counttime(tmp[tmp.size()-1],"23:59");
        }
        if(cnt>fees[0]){
            if((cnt-fees[0])%fees[2]==0){
                ans+=((cnt-fees[0])/fees[2])*fees[3];
            }else{
                ans+=((cnt-fees[0])/fees[2]+1)*fees[3];
            }
        }
        answer.push_back(ans);
    }
    return answer;
}