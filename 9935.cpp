#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<char> s;           //스택
    bool check=true;         //폭발이 일어아는지 안일어나는지 확인
    string str;    
    cin >> str;
    string bomb;
    cin>>bomb;
    stack<char> tmp;        //폭발하는 문자열 임시로 저장
    int strlen=str.length();
    int bomblen= bomb.length();
    for(int i=0;i<strlen;i++){
        s.push(str[i]); 
        check=true;
        if(s.top()==bomb[bomblen-1]&& s.size()>=bomblen){        //스택 마지막이 폭발 문자열 마지막이랑 같거나 스택 사이즈가 폭발 문자열 보다 크거나 같을때
            for(int j=bomblen-1;j>=0;j--){        //폭발 문자열 비교 
                if(bomb[j]!=s.top()){             
                    check=false;                   //다르면 false 그리고 탈출
                    break;
                }
                else if(s.top()==bomb[j]){           //같으면 임시저장소에 넣고 스택 빼기
                    tmp.push(s.top());
                    s.pop();
                }    
            }
            if(check==false){             //폭발문자열이 아니면 다시 돌려놓기
                while(!tmp.empty()){
                    s.push(tmp.top());      
                    tmp.pop();
                }
            }
        }
        while(!tmp.empty()){          //임시저장소 지우기
            tmp.pop();
        }
        
    }
    stack<char> s2;
    string ans;

    while(!s.empty()){              //스택은 후입선출이라 문자열 뽑을려면 뒤집어줘야함
        s2.push(s.top());
        s.pop();
    }
    if(s2.empty()){
        cout<< "FRULA";
    }
    else{
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }
        cout << ans;
    }
}

