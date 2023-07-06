#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    if(a[0]<b[0]){
        return true;
    }else if(a[0]==b[0]){
        if(a[1]<=b[1]){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp);
    vector<int> arr(2);
    arr={0,0};
    for(int i=0;i<targets.size();i++){
        if(targets[i][0]>=arr[1]){
            answer++;
            arr=targets[i];
        }else{
            arr[0]=targets[i][0];
            arr[1]=min(arr[1],targets[i][1]);
        }
    }
    return answer;
}