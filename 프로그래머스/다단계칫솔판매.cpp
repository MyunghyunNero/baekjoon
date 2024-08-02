#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
int parent[10001];
int answer[10001];
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> ans;
    for(int i = 0;i<enroll.size();i++){
        parent[i]=i;
    }
    for(int i = 0;i<enroll.size();i++) {
        m[enroll[i]] = i;
    }
    for(int i = 0 ;i<referral.size();i++) {
        if(referral[i]=="-") continue;
        parent[i]=m[referral[i]];
    }
    for(int i = 0;i<seller.size();i++) {
        int value = amount[i] * 100;
        int idx = m[seller[i]];
        while(value){
            int price = value/10;
            answer[idx] += (value - price);
            value = price;
            if(parent[idx]==idx) break;
            idx = parent[idx];
        }
    }
    for(int i=0;i<enroll.size();i++) {
        ans.push_back(answer[i]);
    }
    return ans;
}