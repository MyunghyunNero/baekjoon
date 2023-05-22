#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool alp[26];
int n,k;
vector<string> v;
int ans;
void dfs(int idx,int cnt){
    if(cnt==k){
        int tempans=0;
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<v[i].length();j++){
                if(!alp[v[i][j]-'a']){
                    flag=false;
                    break;
                }
            }
            if(flag) tempans++;
        }
        ans = max(ans, tempans);
		return;
    }
    for(int i=idx+1;i<26;i++){
        if(alp[i]) continue;
        alp[i]=true;
        dfs(i,cnt+1);
        alp[i]=false;
    }
}
int main(){
    cin>>n>>k;
    if (k < 5) {
		cout << 0 << '\n';
		return 0;
	} else if (k == 26) {
		cout << n << '\n';
		return 0;
	}
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    alp['a'-'a'] = alp['c'-'a'] = alp['i'-'a'] = alp['n'-'a'] = alp['t'-'a'] = true;
	k -= 5;
    dfs(0,0);
    cout<<ans;
}