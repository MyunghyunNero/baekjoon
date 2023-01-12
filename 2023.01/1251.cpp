#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len=s.size();
    string ans="";
    for(int i=1;i<len-1;i++){
        for(int k=1;k<len-i;k++){
            string one = s.substr(0,i);
            reverse(one.begin(),one.end());
            string two = s.substr(i,k);
            reverse(two.begin(),two.end());
            string three = s.substr(i+k);
            reverse(three.begin(),three.end());
            if(ans==""){
                ans=one+two+three;
            }
            if(ans>one+two+three){
                ans=one+two+three;
            }
        }
    }
    cout<<ans;
}