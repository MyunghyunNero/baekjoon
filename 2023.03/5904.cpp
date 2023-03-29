#include <iostream>
#include <string>
using namespace std;
int n;
string s="moo";
char ans;
void search(int n,int h,int len){
    int newlen=2*len+h+3;
    if(n<=3){
        cout<<s[n-1];
        return;
    }
    if(newlen<n){
        search(n,h+1,newlen);
    }else{
        if(n > len && n <= len+h+3){
            if(n-len != 1)
                cout<<'o';
            else
                cout<<'m';
            return;
        }
        else{
            search(n-len-h-3,1,3);
        }
    }
}
int main(){
    
    cin>>n;
    search(n,1,3);

}