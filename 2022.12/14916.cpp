#include <iostream>
using namespace std;
int n;
int ans;
int main(){
    cin>>n;
    int five = n/5;
    if(n%5==0){
        cout << n/5;
        return 0;
    }
    while(five>=0){
        int remain = (n-five*5)%2;
        if(remain==0){
            int two = (n-five*5)/2;
            cout << five +two;
            return 0;
        }
        five--;
    }
    cout<< -1;

}