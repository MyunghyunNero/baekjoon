#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s1;
string s2;
int arr[1002][1002];
int main(){
    cin >>s1;
    cin>>s2;
    int len1=s1.size();
    int len2=s2.size();
    for(int i=0;i<len1;i++){
        for(int k=0;k<len2;k++){
            if(s1[i]==s2[k]){
                arr[i+1][k+1]=arr[i][k]+1;       //같으면 좌대각 에서 +1 
            }else{
                arr[i+1][k+1]=max(arr[i][k+1],arr[i+1][k]); //다르면 왼쪽이랑 위쪽중에 큰 값 채우기
            }
        }
    }
    cout <<arr[len1][len2];
}