#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        map<string,int> m;
        cin >> n;
        for(int i=0;i<n;i++){
            string name,tag;
            cin >>name>>tag;
            if(m.find(tag)==m.end()){
                m.insert({tag,1});
            }
            else{
                m[tag]++;
            }
        }
        int ans=1;
        for(auto i:m){
            ans*=(i.second+1);          //경우의 수 (다른 태그들은 독립시행 , 안 입는거 포함 즉 >=0) 고로 (tag의 수 +1)*(tag의 수 +1)...
        }
        ans-=1;                       // 아예 안입는 수 제외
        cout << ans <<'\n';
    }
}