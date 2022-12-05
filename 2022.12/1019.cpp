#include <iostream>
#include <vector>
using namespace std;
int n;
int check[10];
void subCounting(int num,int ten){
    while (num)
    {
        check[num%10]+=ten;
        num/=10;
    }
    
}
void solve(int num){
    int start =1 ;
    int ten = 1;
    while(start<=num){
        while ((start%10) && start<=num)
        {   
            subCounting(start,ten);
            start++;
        }
        if(num<start) return;
        while(num%10 !=9 && start<=num){
            subCounting(num,ten);
            num--;
        }
        start/=10;
        num/=10;
        for(int i=0;i<=9;i++){
            check[i]+=(num-start +1 ) *ten;
        }
        ten*=10;
    }
}
int main(){
    cin>>n;
    solve(n);
    for(int i=0;i<=9;i++){
        cout << check[i]<<' ';
    }
}
