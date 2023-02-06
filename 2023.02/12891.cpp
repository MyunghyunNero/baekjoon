#include <iostream>
#include <string>
using namespace std;
int s,p;
int arr[4];
int ans;
int check[4];
bool checking(){
    bool check1=true;
    for(int i=0;i<4;i++){
        if(arr[i]>check[i])check1=false;   //조건 실
    }
    return check1;
}
int main(){
    cin>>s>>p;
    string str;
    cin>>str;
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    for(int i=0;i<p;i++){
        if(str[i]=='A') check[0]++;
        else if(str[i]=='C') check[1]++;
        else if(str[i]=='G') check[2]++;
        else if(str[i]=='T') check[3]++;
    }
    if(checking()) ans++;
    for(int i=1;i<=(s-p);i++){
        if(str[i-1]=='A') check[0]--;
        else if(str[i-1]=='C') check[1]--;
        else if(str[i-1]=='G') check[2]--;
        else if(str[i-1]=='T') check[3]--;

        if(str[i+p-1]=='A') check[0]++;
        else if(str[i+p-1]=='C') check[1]++;
        else if(str[i+p-1]=='G') check[2]++;
        else if(str[i+p-1]=='T') check[3]++;
       
        if(checking()) ans++;
    }
    cout<<ans;
}