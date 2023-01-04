#include <iostream>
#include <deque>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<char> v;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            if(v.empty()) v.push_front(c);
            else{
                if(v.front()>=c) v.push_front(c);
                else v.push_back(c);
            }
        }
        for(int i=0;i<n;i++){
            cout<<v[i];
        }
        cout<<'\n';
    }
}