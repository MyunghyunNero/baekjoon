#include <iostream>
#include <string>
using namespace std;
bool arr[1001];
bool check(string s,string temp,int strike,int ball){
    int sCnt=0; //strike 개수
    int bCnt=0;  //ball 개수
    char one=temp[0];
    char two=temp[1];
    char three=temp[2];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[i]==temp[j] && i==j) sCnt++;
            else if(s[i]==temp[j] && i!=j) bCnt++;
        }
    }
    if(strike==sCnt && ball==bCnt) return true;
    return false;
}
bool zeroInclude(int a){
    for(int i=0;i<3;i++){
        if(a%10==0) return true;
        a/=10;
    }
    return false;
}
bool duplicate(int a){
    string str =to_string(a);
    for(int i=0;i<3;i++){
        for(int k=i+1;k<3;k++){
            if(str[i]==str[k]) return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    for(int i=123;i<=987;i++){
        if(zeroInclude(i) || duplicate(i)) continue;
        arr[i]=true;
    }
    for(int i=0;i<n;i++){
        string s;
        int strike,ball;
        cin>>s>>strike>>ball;
        for(int i=123;i<=987;i++){
            if( arr[i]&&check(s,to_string(i),strike,ball) ){
                arr[i]=true;
            }else{
                arr[i]=false;
            }
        }
    }
    int ans=0;
    for(int i=123;i<=987;i++){
        if(arr[i]) ans++;
    }
    cout<<ans;

}
