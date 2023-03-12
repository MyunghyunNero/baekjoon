#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string temp,s,d;
int ans=987654321;
void change(int idx){
    if(idx>0) temp[idx-1] = (temp[idx-1]=='0') ? '1':'0';
    temp[idx]=(temp[idx]=='0')?'1':'0'; 
    if(idx<n-1) temp[idx+1]= (temp[idx+1]=='0')?'1':'0';
}
int main(){
    cin>>n;
    cin>>s>>d;
    for(int i=0;i<2;i++){
        temp=s;
        int cnt=0;
        if(i==0){
            temp[0]=(temp[0]=='0')?'1':'0';
            temp[1]=(temp[1]=='0')?'1':'0';
            cnt++;
        }
        for(int j=1;j<n;j++){
            if(temp[j-1]!=d[j-1]){
                change(j);
                cnt++;
            }
        }
        if(temp==d) ans=min(cnt,ans);
    }
    if(ans!=987654321) cout<<ans;
    else cout<<-1;
    
}