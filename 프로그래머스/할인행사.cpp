#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
bool checkNum(){
    bool check=true;
    
    for(auto i = m.begin(); i!=m.end();i++){
        if(i->second !=0){
            check=false;
            break;
        }
    }
    return check;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0;i<want.size();i++){
        m.insert({want[i],number[i]});
    }
    for(int i=0;i<10;i++){
        if(m.find(discount[i])!=m.end()){
            m[discount[i]]--;
        }
    }
    if(checkNum()) answer++;
    int cnt=0;
    for(int i=10;i<discount.size();i++){
        if(m.find(discount[cnt])!=m.end()){
            m[discount[cnt]]++;
        }
        if(m.find(discount[i])!=m.end()){
            m[discount[i]]--;
        }
        cnt++;
        if(checkNum()) answer++;
        
    }
    return answer;
}