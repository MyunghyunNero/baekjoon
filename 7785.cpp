#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    int n;
    set<string> save;
    cin>>n;
    for(int i=0;i<n;i++){
        string ch;
        string s;
        cin>>s;
        cin>>ch;
        if(ch=="enter"){
            save.insert(s);
        }
        if(ch=="leave"){
            save.erase(s); 
        }
    }
    for (set<string>::reverse_iterator iter = save.rbegin(); iter != save.rend(); iter++) {    //역방향 반복자
	    cout << *iter << "\n";
    }

}