#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >>n >>m;
    if(n>=3&&m>6){              //세로가 3이상이면 위아래는 자유롭게 이동가능 가로가 6보다 크면 4가지 방법 다사용가능
        cout<<m-2;
    }
    else if(n>=3&&m<=6){       //가로가 6보다 작을때 
        if(m>=5){               //5이상은 항상 4가 나와야함 4가 최소
            cout<<4;
        }
        else if(m<5){         //5보다 작을때는 가로 길이만큼 가능 
            cout <<m;
        }
    }
    else if(n<3){         //세로가 3보다 작으면 위아래 이동이 1칸씩으로 제약됨 이때 오른쪽은 항상 2칸씩이동
        if(n==1){
            cout << 1;
        }
        else if(m>=7){
            cout << 4;
        }
        else if(m<7){
            cout << (m+1)/2;
        }
    }
}