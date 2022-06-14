#include <iostream>
#include <vector>
using namespace std;
int n,m;
bool check(vector<long long>& v,int x){        //잘려진 나무의 총 길이와 가져가야하는 나무의 길이 비교
    long long cnt=0;
    for(int i=0;i<n;i++){
        long long temp= v[i]-x;
        if(temp>=0){
            cnt+=temp;
        }
    }
    return cnt>=m;
}
int main(){
    cin >>n>>m;
    vector<long long> v(n);
    long long max=0;
    for(int i=0;i<n;i++){
        cin >>v[i];
        if(max<v[i]){
            max=v[i];
        }
    }
    long long left=0;
    long long right=max;
    long long ans=0;
    while(left<=right){     //가장 큰 길이를 가진 나무까지만 톱날을 자르는게 의미가 있으므로 right는 가장 큰
        long long mid=(left+right)/2;
        int ok=check(v,mid);
        if(ok){
            left=mid+1;
            if(ans<mid){          //높이 최대값을 구해야하므로 
                ans=mid;
            }
        }
        else{
            right=mid-1;
        }
    }
    cout << ans;

}