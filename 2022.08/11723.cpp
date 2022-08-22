#include <iostream>
#include <string>
using namespace std;
int arr[21];
void add(int x){
    arr[x]=1;
}
void remove(int x){
    arr[x]=0;
}
void check(int x){
    cout <<arr[x]<<'\n';
}
void toggle(int x){
    if(arr[x]) arr[x]=0;
    else arr[x]=1;
}
void all(){
    for(int i=1;i<=20;i++){
        arr[i]=1;
    }
}
void empty(){
    for(int i=1;i<=20;i++){
        arr[i]=0;
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(s=="add"){
            int a;
            cin>>a;
            add(a);
        }
        if(s=="remove"){
            int a;
            cin>>a;
            remove(a);
        }
        if(s=="check"){
            int a;
            cin>>a;
            check(a);
        }
        if(s=="toggle"){
            int a;
            cin>>a;
            toggle(a);
        }
        if(s=="all"){
            all();
        }
        if(s=="empty"){
            empty();
        }
    }
}