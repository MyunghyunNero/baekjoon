#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    map<string,int> p;
    vector<string> s;
    string str;
    int n,m;
    cin >>n>>m;
    for(int i=0;i<n;i++){
        cin >> str;
        p.insert({str,i+1});
        s.push_back(str);
    }
    for(int i=0;i<m;i++){
        char ans[21];
        cin >>ans;
        if(ans[0]>='0'&&ans[0]<='9'){
            cout<< s[atoi(ans)-1]<<'\n';
        }
        else{
            cout << p[ans] << '\n';
        }
    }
}