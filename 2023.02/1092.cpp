#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> pork;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pork.push_back(a);
    }
    sort(pork.begin(),pork.end(),greater<>());
    int m;
    cin>>m;
    vector<int> box;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        box.push_back(a);
    }
    sort(box.begin(),box.end(),greater<>());
    
    if(pork[0]<box[0]){
        cout<<-1;
        return 0;
    }
    while(!box.empty()){
        ans++;
        for(int i=0;i<n;i++){
            for(int j=0;j<box.size();j++){
                if(pork[i]>=box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    cout<<ans;
}