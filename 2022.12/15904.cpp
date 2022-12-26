#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    cin>>s;
    int len = s.size();
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='U'&& cnt==0) cnt=1;
        if(s[i]=='C'&&cnt==1) cnt=2;
        if(s[i]=='P' && cnt==2) cnt=3;
        if(s[i]=='C' && cnt==3) {
            cnt=4;
            break;}
    }
    if(cnt==4){
        cout<<"I love UCPC";
    }else{
        cout<<"I hate UCPC";
    }

}