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
    for (auto iter = save.rbegin(); iter != save.rend(); iter++) {
	    cout << *iter << "\n";
    }

}