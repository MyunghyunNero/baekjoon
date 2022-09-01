#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int dx[8] = {0, 0, -1, +1, +1, +1, -1, -1};
int dy[8] = {+1, -1, 0, 0, +1, -1, +1, -1};
void move(string t){
    int r,c;
    int kr,kc;
    int i=0;
    r=s2[0]-'A';
    c=s2[1]-'1';
    kr=s1[0]-'A';
    kc=s1[1]-'1';
    if(t=="R"){
        
    }
    if(t=="L"){
       i+=1;
    }
    if(t=="B"){
        i+=2;
    }
    if(t=="T"){
        i+=3;
    }
    if(t=="RT"){
        i+=4;
    }
    if(t=="LT"){
        i+=5;
    }
    if(t=="RB"){
        i+=6;
    }
    if(t=="LB"){
        i+=7;
    }
    int nky=kr+dy[i];
    int nkx=kc+dx[i];
    if (nkx < 0 || nkx > 7 || nky < 0 || nky > 7 ) {
			return;
	}
    if (nkx == c && nky == r) {
		int nx = c + dx[i];
		int ny = r + dy[i];
		//돌을 옮겻더니 밖으로 나가면
        if (nx < 0 || nx >7 || ny < 0 || ny >7) {
			return;
		}
		else {
			//돌 옮기기
			s2[0]= ny+'A';
            s2[1] =nx+'1';
		}
	}
    s1[0]=nky+'A';
    s1[1]=nkx+'1';
}
int main(){
    int n;
    cin>>s1>>s2;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        move(temp);
    }
    cout << s1<<'\n'<<s2;


}