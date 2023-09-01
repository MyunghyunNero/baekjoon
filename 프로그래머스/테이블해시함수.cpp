#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int index;
bool cmp(vector<int> a, vector<int> b){
    if(a[index]<b[index]){
        return true;
    }else if(a[index]==b[index]){
        if(a[0]>b[0]){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    index=col-1;
    sort(data.begin(),data.end(),cmp);
    for(int i=row_begin-1;i<row_end;i++){
        int sum=0;
        for(int j=0;j<data[i].size();j++){
            sum+=(data[i][j]%(i+1));
        }
        answer^=sum;
    }
    return answer;
}