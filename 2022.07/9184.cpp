#include <iostream>
using namespace std;
int w[21][21][21];
int rew(int a,int b,int c){
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if( a > 20 || b > 20 || c > 20){
        return rew(20,20,20);
    }

    if(a < b && b < c){
        if(w[a][b][c]!=0){
            return w[a][b][c];
        }else{
        return w[a][b][c]=rew(a,b,c-1)+rew(a,b-1,c-1)-rew(a,b-1,c);
        }
        
    }else{
        if(w[a][b][c]!=0){
            return w[a][b][c];
        }else{
        return w[a][b][c]=rew(a-1,b,c)+rew(a-1,b-1,c)+ rew(a-1,b,c-1)-rew(a-1,b-1,c-1);
        }
    }
}
int main(){
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << rew(a, b, c) << endl;
    }
}