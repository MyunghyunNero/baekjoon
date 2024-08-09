#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> arr;
vector<double> arr2;
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    while(k>=1) {
        arr.push_back(k);
        if(k==1) break;
        if(k%2==0) {
            k/=2;
        }else{
            k=k*3+1;
        }
    }
    double sum = 0;
    arr2.push_back(0);
    for(int i=0;i<arr.size()-1;i++) {
        double broad = ((double)arr[i] + (double)arr[i+1])/2.0;
        sum+=broad;
        arr2.push_back(sum);
    }
    int len = arr.size()-1;
    for(int i=0;i<ranges.size();i++) {
        int a = ranges[i][0];
        int b = ranges[i][1];
        if(a>b+len) {
            answer.push_back(-1);
        }else{
            answer.push_back(arr2[len + b] - arr2[a]);
        }
        
    }
    return answer;
}