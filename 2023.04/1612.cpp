#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    if(!(n % 2 && n % 5)) {
        cout<<-1;
        return 0;
    }
    
    for(int i=1,j=0;;i++){
        j=(10*j+1)%n;
        if(!(j%n)){
            cout<<i;
            break;
        }
    }
    
}