#include <iostream>
#include <vector>
using namespace std;
void setPaper(int a,int b);
int n;
int arr[100][100];
int main(){
    cin>>n;
    int sum=0;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        setPaper(a,b);
    }
    for(int i=0;i<100;i++){
        for(int k=0;k<100;k++){
            if(arr[i][k]==1){
                sum++;
            }
        }
    }
    cout<<sum;
}

void setPaper(int a,int b){
    for(int i =a ; i<a+10;i++){
        for(int k=b ; k<b+10;k++){
            arr[i][k]=1;
        }
    }
}