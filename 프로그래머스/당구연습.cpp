#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int calrange(int startx,int starty,int x,int y){
    
    return pow(startx-x,2)+pow(starty-y,2);
}
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(int i=0;i<balls.size();i++){
        int x=balls[i][0];
        int y=balls[i][1];
        vector<int> v;
        if(startY==y){
            if(startX>x){
                v.push_back(calrange(2*m-startX,startY,x,y));
            }
            if(startX<x){
                v.push_back(calrange(-startX,startY,x,y));
            }
        }else{
            v.push_back(calrange(2*m-startX,startY,x,y));
            v.push_back(calrange(-startX,startY,x,y));
        }
        if(startX==x){
            if(startY>y){
                v.push_back(calrange(startX,2*n-startY,x,y));
            }
            if(startY<y){
                v.push_back(calrange(startX,-startY,x,y));
            }
        }else{
            v.push_back(calrange(startX,2*n-startY,x,y));
            v.push_back(calrange(startX,-startY,x,y));
        }
        
        sort(v.begin(),v.end());
        answer.push_back(v[0]);
    }
    return answer;
}