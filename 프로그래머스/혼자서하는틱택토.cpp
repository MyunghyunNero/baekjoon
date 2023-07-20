#include <string>
#include <vector>

using namespace std;
bool xThree;
bool oThree;
int o;
int x;
int solution(vector<string> board) {
    int answer = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='O') o++;
            if(board[i][j]=='X') x++;
        }
    }
    for(int i=0;i<3;i++){
        if(board[i]=="XXX") xThree=true;
        if(board[i]=="OOO") oThree=true;
    }
    for(int i=0;i<3;i++){
        string s;
        for(int j=0;j<3;j++){
            s+=board[j][i];
        }
        if(s=="XXX") xThree=true;
        if(s=="OOO") oThree=true;
        
    }
    string temp;
    for(int i=0;i<3;i++){
        temp+=board[i][i];
    }
    if(temp=="XXX") xThree=true;
    if(temp=="OOO") oThree=true;
    temp="";
    for(int i=0;i<3;i++){
        temp+=board[i][2-i];
    }
    if(temp=="XXX") xThree=true;
    if(temp=="OOO") oThree=true;
    if(oThree && xThree) answer=0;
    if(o-x<0 || o-x>1) answer=0;
    if(oThree && !xThree){
        if(o-x!=1) answer=0;
    }
    if(!oThree && xThree){
        if(o-x!=0) answer=0;
    }
    
    return answer;
}