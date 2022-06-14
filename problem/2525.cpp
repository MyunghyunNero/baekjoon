#include <iostream>
using namespace std;
int main(){
    int t,m,n;
    cin >>t>>m>>n;
    int t2=n/60;
    int m2=n%60;
    if(m+m2>=60){
        cout << (t+t2+1)%24 << " "<<(m+m2)%60;
    }else{
        cout << (t+t2)%24 << " "<<(m+m2)%60;
    }
}