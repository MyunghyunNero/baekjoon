#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[402];
int arr[22][22];
int n;
int student;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.second>b.second){
        return true;
    }else if(a.second== b.second){
        if(a.first.first<b.first.first){
            return true;
        }else if(a.first.first==b.first.first){
            if(a.first.second<b.first.second){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int blank(int x,int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 || nx >n || ny<1 ||ny>n) continue;
        if(arr[nx][ny]==0){cnt++;}
    }
    return cnt;
}
int likeFriend(int x,int y,int num){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 || nx >n || ny<1 ||ny>n) continue;
        if(arr[nx][ny]==0) continue;
        for(int j=0;j<v[num].size();j++){
            if(arr[nx][ny] == v[num][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

void seach(int num){
    vector<pair<pair<int,int>,int>> pv;
    int maxlike=0;
    for(int i=1;i<=n;i++){    
        for(int k=1;k<=n;k++){
        	if(arr[i][k]==0){
            	int cntfriend=likeFriend(i,k,num);
            	maxlike=max(maxlike,cntfriend);        //주변 좋아하는 사람 많은지 체크
            	pv.push_back({{i,k},cntfriend});
        	}
        }
    }
    sort(pv.begin(),pv.end(),cmp);
    int cnt=0;
    for(int i=0;i<pv.size();i++){
        if(pv[i].second==maxlike) cnt++;
    }
    if(cnt==1){
        arr[pv[0].first.first][pv[0].first.second]=num;
    }else{
        vector<pair<pair<int,int>,int>> bv;
        for(int i=0;i<pv.size();i++){
            if(pv[i].second==maxlike){
                int bcnt=blank(pv[i].first.first,pv[i].first.second);
                bv.push_back({{pv[i].first.first,pv[i].first.second},bcnt});
            }
        }
        sort(bv.begin(),bv.end(),cmp);
        arr[bv[0].first.first][bv[0].first.second]=num;
    }
}
int main(){
    cin >> n;
    student=n*n;
    for(int i=1;i<=student;i++){
        int a;
        cin>>a;
        for(int j=0;j<4;j++){
            int c;
            cin>>c;
            v[a].push_back(c);
        }
        seach(a);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            int likefriend= likeFriend(i,k,arr[i][k]);
            if(likefriend==0){
                ans+=0;
            }else if(likefriend==1){
                ans+=1;
            }else if(likefriend==2){
                ans+=10;
            }else if(likefriend==3){
                ans+=100;
            }else if(likefriend == 4){
                ans+=1000;
            }
        }
    }
    cout<<ans;


}