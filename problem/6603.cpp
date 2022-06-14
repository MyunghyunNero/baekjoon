#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    while(1){
        int n;
        cin >>n; 
        if(n==0){            //탈출
            break;
        }
        vector<int> a(n);      
        for(int i=0;i<n;i++){           //집합 수
            cin>>a[i];
        }
        vector<int> d;
        for(int i=0;i<n-6;i++){        //0과 1(6개)을 넣어 순열 함수를 사용한다음 그 위치 값 그대로 원소 6개 집합 만들기
            d.push_back(0);
        }
        for(int i=0;i<6;i++){
            d.push_back(1);
        }
        vector<vector<int>> ans;
        do{
            vector<int> cur;
            for(int i=0;i<n;i++){
                if(d[i]==1){                     //1일때 위치값을 집합배열 그대로 넣기
                    cur.push_back(a[i]);
                }
            }
            ans.push_back(cur);
        }while(next_permutation(d.begin(),d.end()));      //다음 순열
        sort(ans.begin(),ans.end());          //정렬
        for(auto &v :ans){                      //출력
            for(int i=0;i<v.size();i++){
                cout <<v[i]<<' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}