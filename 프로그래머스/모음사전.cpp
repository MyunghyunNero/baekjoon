#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
string arr[]={"A","E","I","O","U"};
void dfs(string s){
    if(s.size()>=5) return;
    for(int i=0;i<5;i++){
        v.push_back(s+arr[i]);
        dfs(s+arr[i]);
    }
}
int solution(string word) {
    
    int answer = 0;
    dfs("");
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i]==word){
            answer=i+1;
            break;
        }
    }
    return answer;
}