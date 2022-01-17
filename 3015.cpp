#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >>v[i];
    } 
    long long cnt=0;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        pair<int,int> p={v[i],1};
        while(!s.empty()){
            if(s.top().first<=v[i]){                //v[i]값이 스택 보다 크면
                cnt+=(long long)s.top().second;       //더하기
                if(s.top().first==v[i]){                    //값이 같을때
                    p.second+=s.top().second;
                }
                s.pop();                            //스택에는 자신보다 큰 값이 나오지 않는 이상 스택에 저장 이유는 다른 값을 볼 가능성이 있기 때문에
            }else{
                break;
            }
        }
        
        if(!s.empty()){          //바로 옆이랑 쌍을 이룰수 있으므로 비워있지 않으면 1 더하기
            cnt+=1ll;
        }
        s.push(p);
    }
    cout << cnt;
}