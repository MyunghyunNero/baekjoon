#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    int n,c;
bool check(vector<long long>& v,int x){             //임의의 거리 x값
    long long last=v[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if((v[i]-last)>=x){                    // 공유기 설치한 마지막 집과 i의 집거리 차이가 x값보다 크거나 같으면
            last=v[i];
            cnt++;
        }
    }
    return cnt>=c;                          //공유기 설치 개수가 지정한 공유기 개수보다 크거나 같으면 참

}
int main(){
    cin>>n>>c;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long left=1;                          //거리 최소는 1
    long long right=v[n-1]-v[0];               //거리 최대는 마지막 집에서 처음 집거리 뺀거
    long long ans=1;
    while(left<=right){                               //거리를 값으로 이분 탐색
        long long mid=(left+right)/2;
        if(check(v,mid)){
            left=mid+1;
            if(ans<mid){
                ans=mid;
            }
        }
        else{
            right=mid-1;
        }
    }
    cout << ans;
}