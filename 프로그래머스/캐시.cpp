#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
// 너무 잘 못품 다시 
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(int i=0; i < cities.size(); i++){
        for(int j=0; j<cities[i].size();j++){
            cities[i][j] = tolower(cities[i][j]);
        }
    }
    for(int i = 0; i < cities.size() ;i++) {
        if(m.size() < cacheSize){
            map<string,int>::iterator iter = m.find(cities[i]);
            if(iter != m.end()) {
                answer+=1;
                iter->second = i;
            }else{
                m.insert({cities[i],i});
                answer+=5;
            }
        }else if(m.size() == cacheSize && cacheSize>0){
            map<string,int>::iterator iter = m.find(cities[i]);
            if(iter == m.end()) {
                int minV=999999;
                string mIndex="";
                for(pair<string,int> index : m){
                    if(minV>index.second){
                        minV=index.second;
                        mIndex=index.first;
                    }
                }
                m.erase(mIndex);
                m.insert({cities[i],i});
                answer+=5;
            }else{
                answer+=1;
                iter->second=i;
            }
        }else{
            answer+=5;
        }
    }
    return answer;
}