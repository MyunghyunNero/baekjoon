#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    int n,m;
    string str;
    set<pair<string,int>>::iterator iter;
    cin>>n>>m;
    set<pair<string,int>> s;
    while(n--){
        cin>>str;
        s.insert(make_pair(str,0));
    }
    int cnt=0;
    while(m--){
        cin>>str;
        iter=s.find(pair<string,int>(str,0));
        if(iter!=s.end()){
            s.insert(iter,make_pair(str,1));       //set값은 고유 하기 때문에 다시 second값 1로 삽입 1이면 이미 있는 문장
            cnt++;                                  //갯수
        }
    }
    cout << cnt<<'\n';
    for(iter=s.begin();iter!=s.end();iter++){        //출력
        if((*iter).second==1){
            cout << (*iter).first<<'\n';
        }
    }
    
}