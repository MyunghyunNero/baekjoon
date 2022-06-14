#include <iostream>
#include <vector>
using namespace std;
int n,m;
long long ed=0;
bool check(vector<long long>& v,long long x){        //x라는 시간을 받고 그 시간동안 놀이기구 이용한 수 cnt,n보다 작으면 참
    long long cnt=m;             //0분에 총 m명 들어갈 수 있다.
    for(int i=0;i<m;i++){
        cnt+=(x/v[i]);
    }
    return cnt<n;
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >>n>>m;
    vector<long long> v(m);
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    if(n<=m){               //n명이m개의 놀이기구 보다 작으면 0분걸리므로 그냥 n 출력
        cout << n;
        return 0;
    }
    long long left=0;
    long long right=2000000000LL * 30LL;
    while(left<=right){                //이분탐색 n보다 작으면 참 이므로 mid값은 n이 되기 1분전 시간이 나온다.
        long long mid=(right+left)/2;
        if(check(v,mid)){
            left=mid+1;
            ed=mid;                     //n이 되기 1분전 시간을 ed에 저장
        }
        else{
            right=mid-1;
        }
    } 
    for(int i=0;i<m;i++){                  //n명이 되기 위한 1분이 지날떄 총 몇명이 남는지 확인
        n-=(ed/v[i]);                       
    }
    n-=m;                            //ed+1분이 될 때 n명 수만큼 놀이기구 입장
    int ans=0;
    for(int i=0;i<m;i++){                //n번수 만큼 놀이기구 차례로 탑승
        if(((ed+1)%v[i])==0){
            ans=i;
            n--;
            if(n==0){
                break;
            }
        }
    }
    cout <<ans+1;        
    

}