#include <iostream>
#include <deque>
#include <string>
using namespace std;
int t;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    deque<int>::iterator iter;
    deque<int>::reverse_iterator riter;
    while(t--){
        string temp,oper;
        bool check=false;
        bool error=false;
        deque<int> dq;
        cin>>oper;
        cin>>n;
        cin>>temp;
        string s="";
        for (int i = 0; i<temp.length();i++) {
            if (isdigit(temp[i])) {
                s += temp[i];
            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }
        for(int i=0;i<oper.length();i++){
            if(oper[i]=='R'){
                if(check){
                    check=false;
                }
                else{
                    check=true;
                }
            }
            else{
                if(dq.empty()){
                        cout << "error"<<'\n';
                        error=true;
                        break;
                }
                if(check){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }
        if(!error){
            cout<<'[';
        }
        if(check && !dq.empty()){
            for(riter=dq.rbegin();riter!=dq.rend();riter++){
                if(riter==dq.rend()-1){
                    cout <<*riter;
                }else{
                    cout <<*riter<<',';
                }
            }
        }else if(!check&&!dq.empty()){
            for(iter=dq.begin();iter!=dq.end();iter++){
                if(iter==dq.end()-1){
                    cout <<*iter;
                }else{
                    cout <<*iter<<',';
                }
            }
        }
        if(!error){
            cout<<']'<<'\n';
        }
    }
}