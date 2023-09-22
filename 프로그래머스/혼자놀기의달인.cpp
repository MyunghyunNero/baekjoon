#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check[101];
vector<int> v;
int solution(vector<int> cards) {
    int answer = 1;
    for(int i=0;i<cards.size();i++){
        int cnt=0;
        if(!check[i]){
            check[i]=true;
            int next=cards[i]-1;
            cnt++;
            while(!check[next]){
                cnt++;
                check[next]=true;
                next=cards[next]-1;
            }
            v.push_back(cnt);
        }
    }
    sort(v.begin(),v.end(),greater());
    if(v.size()<2){
        return 0;
    }
    return v[0]*v[1];
}