#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int arr[26]={0};
int check[26]={0};
int ans;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    n--;
    int len =s.size();
    for(int i=0;i<s.size();i++){
        arr[s[i]-'A']++;
    }
    while(n--){
        int cnt=0;
        string temp;
        cin>>temp;
        int tempLen=temp.size(); 
        memset(check,0,26*sizeof(int));
        for(int i = 0;i<temp.size();i++){
            check[temp[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            cnt+=abs(arr[i]-check[i]);
        }
        if(len==tempLen){
            if(cnt<=2) ans++;
        }else{
            if(cnt<=1) ans++;
        }
    }
    cout<<ans;
    
}