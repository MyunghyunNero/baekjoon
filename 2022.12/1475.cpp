#include <iostream>
#include <string>
using namespace std;
int check[10];
int mid;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        check[s[i]-'0']++;
    }
    int six=check[6];
    int nine=check[9];
    if((six+nine)%2==1){
        mid = (six+nine)/2 +1;
    }else{
        mid = (six + nine)/2;
    }
    check[6]=mid;
    check[9]=mid;
    int max=-1;
    for(int i=0;i<=9;i++){
        if(max<check[i]) max =check[i];
    }
    cout<<max;
}