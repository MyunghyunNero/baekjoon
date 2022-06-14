#include <iostream>
using namespace std;
void check(int a,int b){
    if(b%a==0){
        cout<<"factor"<<'\n';
        return;
    }
    if(a%b==0){
        cout<<"multiple"<<'\n';
        return;
    }
    cout << "neither"<<'\n';

}
int main(){
    int a,b;
    while(1){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        check(a,b);
    }
}