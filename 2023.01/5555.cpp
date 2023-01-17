#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n;
    cin>>n;
    int cnt=0;
    while(n--){
        string temp;
        cin>>temp;
        temp+=temp;
        if(temp.find(s)!=string::npos){
            cnt++;
        }
    }
    cout<<cnt;

}