#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int> m;
    while(n--){
        string s;
        cin>>s;
        s=s.substr(s.find('.')+1);
        if(m.find(s)!=m.end()){
        	m.find(s)->second++;
        }else{
            m.insert({s,1});
        }
        
    }
    for (auto iter = m.begin() ; iter !=  m.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
}