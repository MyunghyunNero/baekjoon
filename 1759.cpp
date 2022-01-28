#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check(string password){     //자음 최소 2개 이상 모음 최소1개이상 조건 충족하는지
    int ja=0;
    int mo=0;
    for(char c:password){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            mo++;
        }else{
            ja++;
        }
    }
    return mo>=1&&ja>=2;
}
void go(int n,vector<char> &c,string password,int i){
    if(password.length()==n){                             //패스워드 길이가 주어진 길이랑 같을 떄 출력
        if(check(password)){
            cout<<password<<'\n';
        }
        return;
    }
    if(i>=c.size()){
        return;
    }
    go(n,c,password+c[i],i+1);                      //i번째 패스워드 추가하고 다음
    go(n,c,password,i+1);                            //i번쨰 패스워드 추가 안하고 다음
}
int main(){
    int l,c;
    cin>>l>>c;
    vector<char> carr(c);
    string str="";
    for(int i=0;i<c;i++){
        cin>>carr[i];
        cin.ignore();
    }
    sort(carr.begin(),carr.end());          //정령후 이용
    go(l,carr,str,0);


}