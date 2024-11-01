#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
// <<x,y>,time>,
map<pair<pair<int,int>,int>,int> m;
void update(pair<pair<int,int>,int> key) {
    if(m.find(key)!=m.end()) {
        m[key]++;
    }else{
        m.insert({key,1});
    }
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    for(vector<int> route : routes) {
        int time = 0 ;
        for(int i=0;i<route.size()-1;i++) {
            int start = route[i]-1;
            int dest = route[i+1]-1;
            int y = points[start][0];
            int x = points[start][1];
            int dirY = points[dest][0] - y > 0 ? 1 : -1;
            int dirX = points[dest][1] - x > 0 ? 1 : -1;
            if(i==0) {
                update({{y,x},time++});
            }
            while(y!=points[dest][0]) {
                y+=dirY;
                update({{y,x},time++});
            }
            while(x!=points[dest][1]){
                x+=dirX;
                update({{y,x},time++});
            }
        }
    }
    for(auto& value : m) {
        if(value.second>1) {
            answer++;
        }
    }
    
    
    return answer;
}