#include <iostream>
#include <set>
using namespace std;
set<int> st;
set<string> mul;
int v[3];
void dfs(int a,int b,int c){
    string str=to_string(a)+to_string(b)+to_string(c);
    if(mul.find(str)==mul.end()){
        mul.insert(str);
    }else{
        return ;
    }
    if(a==0){
        if(st.find(c)==st.end()){
            st.insert(c);
        }else{
            return;
        }
    }
    if(a!=0){
        if(a+b<=v[1]){
            dfs(0,a+b,c);
        }else{
            dfs(a-(v[1]-b),v[1],c);
        }
        if(a+c<=v[2]){
            dfs(0,b,a+c);
        }else{
            dfs(a-(v[2]-c),b,v[2]);
        }
    }
    if(b!=0){
        if(b+a<=v[0]){
            dfs(a+b,0,c);
        }else{
            dfs(v[0],b-(v[0]-a),c);
        }
        if(b+c<=v[2]){
            dfs(a,0,b+c);
        }else{
            dfs(a-(v[2]-c),b,v[2]);
        }
    }
    if(c!=0){
        if(c+a<=v[0]){
            dfs(c+a,b,0);
        }else{
            dfs(v[0],b,c-(v[0]-a));
        }
        if(b+c<=v[1]){
            dfs(a,c+b,0);
        }else{
            dfs(a,v[1],c-(v[1]-b));
        }
    }
}
int main(){
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
    dfs(0,0,v[2]);
    for(auto iter=st.begin();iter!=st.end();iter++){
        cout<<*iter<<" ";
    }
}