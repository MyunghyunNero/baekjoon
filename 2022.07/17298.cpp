#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
int arr[1000001];
int neg[1000001];
int n;
int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        while(!s.empty()&&arr[s.top()]<arr[i]){
            neg[s.top()]=arr[i];
            s.pop();            
        }
        s.push(i);
    }
    while(!s.empty()){
        neg[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout << neg[i]<<' ';
    }

}