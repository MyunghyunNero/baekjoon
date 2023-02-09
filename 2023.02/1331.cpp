#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr[6][6];

bool check1(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr[i][j]==0) return false;
        }
    }
    return true;
}
int main(){
    vector<string> v;
    string start;
    cin>>start;
    v.push_back(start);
    int startrow = start[0]-'A';
    int startcol = start[1]-'1';
    arr[startrow][startcol]++;
    bool check2=true;
    string end;
    for(int i=1;i<36;i++){
        string s;
        cin>>s;
        if(i==35){
            end=s;
        }
        v.push_back(s);
        int Brow = v[i-1][0]-'A';
        int Bcol = v[i-1][1]-'1';
        int Arow = v[i][0]-'A';
        int Acol = v[i][1]-'1';
        if(!((abs(Brow-Arow)==2 && abs(Bcol-Acol)==1) || (abs(Brow-Arow)==1 && abs(Bcol-Acol)==2))){
            check2=false;
        }
        arr[Arow][Acol]++;
    }
    bool check=false;
    int endRow = end[0] - 'A';
    int endCol = end[1] - '1';
    if(((abs(startrow-endRow)==2 && abs(startcol-endCol)==1) || (abs(startrow-endRow)==1 && abs(startcol-endCol)==2))&&check1()&&check2){
        check =true;
    }
    if(check){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }
}