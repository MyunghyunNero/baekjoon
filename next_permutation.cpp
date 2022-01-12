#include <iostream>
using namespace std;
void swap(int &a,int &b){      //참조에 위한 호출
    int temp=a;
    a=b;
    b=temp;
}
bool next_permutation(int *a , int n){
    int i=n-1;
    while(i>0 && a[i-1]>=a[i])i-=1;         //뒤에서 부터 내림차순이 아니게 될 때를 구함
    if(i<=0) return false;                  //없으면 순열의 끝
    int j=n-1;
    while(a[j]<=a[i-1]) j-=1;               //다시 뒤에서 부터 내림차순 아니게 될떄 까지 반복하며 값이 더 클 때 까지 반환
    swap(a[i-1],a[j]);                      //바꿔줌
    j=n-1;
    while(i<j){
        swap(a[i],a[j]);                   //남은 거도 오름차순이 되게 다 바꿔줌
        i+=1;j-=1;
    }
    return true;
}