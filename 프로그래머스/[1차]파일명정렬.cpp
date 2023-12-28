#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<string> a, vector<string> b){
    string aHead="";
    string bHead="";
    for(char c : a[1]){
        aHead+=tolower(c);
    }
    for(char c : b[1]){
        bHead+=tolower(c);
    }
    if(aHead<bHead){
        return true;
    }else if(aHead == bHead){
        int aNumber = stoi(a[2]);
        int bNumber = stoi(b[2]);
        if(aNumber<bNumber){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
vector<vector<string>> v;
vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(string file : files) {
        vector<string> tmp;
        tmp.push_back(file);
        string head = "";
        int start =0;
        for(int i=start ;i<file.size() ; i++) {
            if(!(file[i]>='0' && file[i]<='9')){
                head+=file[i];
            }else{
                start=i;
                break;
            }
        }
        tmp.push_back(head);
        string number = "";
        for(int i = start ; i<start+5;i++){
            if(file[i]>='0' && file[i]<='9'){
                number+=file[i];
            }else{
                break;
            }
        }
        tmp.push_back(number);
        v.push_back(tmp);
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(vector<string> v1 : v){
        answer.push_back(v1[0]);
    }
    return answer;
}