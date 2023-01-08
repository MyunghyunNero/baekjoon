#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<string> v;
        int n;
        cin>>n;
        bool check=true;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            int curLen=v[i].length();
            int nextLen=v[i+1].length();
            if(curLen>=nextLen) continue;
            if (v[i + 1].substr(0, curLen)== v[i]) {
                check = false;
                cout << "NO" << '\n';
                break;
            }
        }
        if (check==true) {
            cout << "YES" << '\n';
        }
        v.clear();
    }
}