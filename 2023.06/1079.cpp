#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int enjin;
int arr[17][17];
int particnt;
int ans;
bool die[17];
void dfs(int people ,int night){
    if(people==1){
        ans=max(ans,night);
        return;
    }
    if(people%2==1){
        int maxguilt=0;
        int maxindex=0;
        for(int i=0;i<n;i++){
            if(!die[i]){
                if(maxguilt<v[i]){
                    maxguilt=v[i];
                    maxindex=i;
                }
            }
        }
        if(maxindex=enjin){
            ans=max(ans,night);
            return;
        }else{
            die[maxindex]=true;
            dfs(people-1,night+1);
        }
    }else{
        for(int i=0;i<n;i++){
            if(!die[i] && i!=enjin){
                die[i]=true;
                for(int j=0;j<n;j++){
                    v[j]=v[j]+arr[i][j];
                }
                dfs(people-1,night);
                for(int j=0;j<n;j++){
                    v[j]=v[j]-arr[i][j];
                }
            }
        }
    }
}
int main(){
    cin>>n;
    particnt=n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cin>>enjin;
    dfs(n,0);
    cout<<ans;
    
}