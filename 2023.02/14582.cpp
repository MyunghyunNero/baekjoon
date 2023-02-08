#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> j;
    vector<int> s;
    for(int i=0;i<9;i++){
        int a;
        cin>>a;
        j.push_back(a);
    }
    for(int i=0;i<9;i++){
        int a;
        cin>>a;
        s.push_back(a);
    }
    int jSum=0;
    int sSum=0;
    bool check=false;
    for(int i=0;i<9;i++){
        jSum+=j[i];
        if(jSum>sSum){
            check=true;
            break;
        }
        sSum+=s[i];
    }

    if(check){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}