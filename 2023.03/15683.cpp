#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[9][9];
vector<pair<int,int>> cctv;
int ans=987654321;
int bfs(){
    int temp[9][9];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=arr[i][j];
        }
    }
    int idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0 || temp[i][j]==6 ||temp[i][j]==-1) continue;
            else if(temp[i][j]==1){
                int direct=cctv[idx].second;
                if(direct==0){
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }else if(direct==1){
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else if(direct==2){
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }else{
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }
            }else if(temp[i][j]==2){
                int direct=cctv[idx].second;
                if(direct==0){
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else{
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }
            }else if(temp[i][j]==3){
                int direct=cctv[idx].second;
                if(direct==0){
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else if(direct==1){
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }else if(direct==2){
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else{
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }
            }else if(temp[i][j]==4){
                int direct=cctv[idx].second;
                if(direct==1){
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else if(direct==2){
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }else if(direct==3){
                    for(int k=j+1;k<m;k++){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                }else{
                    for(int k=i+1;k<n;k++){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                    for(int k=j-1;k>=0;k--){
                        if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                        else if(temp[i][k]>0&&temp[i][k]<6) continue;
                        else break;
                    }
                    for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                    }
                }
            }else if(temp[i][j]==5){
                for(int k=i-1;k>=0;k--){
                        if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                        else if(temp[k][j]>0&&temp[k][j]<6) continue;
                        else break;
                }
                for(int k=j+1;k<m;k++){
                    if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                    else if(temp[i][k]>0&&temp[i][k]<6) continue;
                    else break;
                }
                for(int k=i+1;k<n;k++){
                    if(temp[k][j]==0 || temp[k][j]==-1) temp[k][j]=-1;
                    else if(temp[k][j]>0&&temp[k][j]<6) continue;
                    else break;
                }
                for(int k=j-1;k>=0;k--){
                    if(temp[i][k]==0 || temp[i][k]==-1) temp[i][k]=-1;
                    else if(temp[i][k]>0&&temp[i][k]<6) continue;
                    else break;
                }
            }
        }
    }
    int cnt=0;;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0) cnt++;
        }
    }
    return cnt;
}
void dfs(int cnt){
    if(cnt==cctv.size()){
        int res=bfs();
        if(ans>res) ans=res;
        return;
    }
    int prev=cctv[cnt].first;
    if(cctv[cnt].first==1){
        for(int i=0;i<4;i++){
            cctv[cnt].second=i;
            dfs(cnt+1);
            cctv[cnt].second=prev;
        }
    }else if(cctv[cnt].first==2){
        for(int i=0;i<2;i++){
            cctv[cnt].second=i;
            dfs(cnt+1);
            cctv[cnt].second=prev;
        }
    }else if(cctv[cnt].first==3){
        for(int i=0;i<4;i++){
            cctv[cnt].second=i;
            dfs(cnt+1);
            cctv[cnt].second=prev;
        }
    }else if(cctv[cnt].first==4){
        for(int i=0;i<4;i++){
            cctv[cnt].second=i;
            dfs(cnt+1);
            cctv[cnt].second=prev;
        }
    }else{
        dfs(cnt+1);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]>0 && arr[i][j]<6){
                cctv.push_back({arr[i][j],0});
            }
        }
    }
    dfs(0);
    cout<<ans;

}