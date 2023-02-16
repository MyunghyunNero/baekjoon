#include <iostream>
#include <string>
using namespace std;


bool checking(string s,int left, int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int pointer(string s){
    int len= s.size();
    int check=0;
    int left=0;
    int right=len-1;
    while(left<right){
        if(s[left]==s[right]){
            left++;
            right--;
        }else if(s[left]!=s[right]){
            if(checking(s,left+1,right)){
                check=1;
                break;
            }else if(checking(s,left,right-1)){
                check=1;
                break;
            }else{
                check=2;
                break;
            }
        }
    }
    return check;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        cout<<pointer(str)<<'\n';
    }
}