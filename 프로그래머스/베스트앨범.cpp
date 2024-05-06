#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string,vector<pair<int,int>>> m;
map<string,int> sum;
bool mapCmp(pair<string, vector<pair<int,int>>> &a, pair<string, vector<pair<int,int>>> &b) {
    
    if(sum[a.first]>sum[b.first]){
        return true;
    }else{
        return false;
    }
}
bool vCmp(pair<int,int> &a, pair<int,int> &b) {
    if(a.first>b.first) {
        return true;
    }else if(a.first == b.first) {
        if(a.second < b.second){
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i < genres.size();i++) {
        m[genres[i]].push_back({plays[i],i});
        sum[genres[i]]+=plays[i];
    }
    vector<pair<string, vector<pair<int,int>>>> mSort(m.begin(), m.end());
    sort(mSort.begin(),mSort.end(),mapCmp);
    for(pair<string, vector<pair<int,int>>> v : mSort) {
        vector<pair<int,int>> tmp = v.second;
        sort(tmp.begin(),tmp.end(),vCmp);
        int minSize = min<int>(2,tmp.size());
        for(int i = 0 ; i<minSize;i++){
            answer.push_back(tmp[i].second);
        }
    }
    
    return answer;
}