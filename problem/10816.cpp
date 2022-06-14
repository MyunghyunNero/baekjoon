#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int upper_bound(vector<int> &v1,int target, int size){  //중복된 값 바로 다음 값 위치 찾기
    int start=0;
    int end=size-1;
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(v1[mid]>target){   //탐색 값이 타겟 값보다 크면 끝을 중간값 넣기 즉, 탐색값 보다 큰 다음 값 위치로 맞추어짐
            end=mid;
        }
        else{
            start=mid+1;
        }
    }
    return end;
}

int rower_bound(vector<int> &v1,int target,int size){ //탐색 중복 값 중 가장 맨 앞쪽 출력
    int start=0;
    int end=size-1;
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(v1[mid]>=target){  //중복된 값들은 다 end에 넣음 이러면 중복 된 값이 걸려도 mid 값은 앞으로 가면서 맨앞으로 가게됨
            end=mid;
        }
        else{
            start=mid+1;
        }
    }
    return end;
}

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        int start =rower_bound(v,t,n);
        int end=upper_bound(v,t,n);
        if(end==n-1&&v[end]==t){     // 마지막 값이 중복되면 upper_bound가 그 다음 위치를 못 가져오므로 예외처리
            end++;
        }
        cout << end-start<<' ';
    }
}

