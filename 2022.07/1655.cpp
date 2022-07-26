#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int> max_q;
priority_queue<int,vector<int>,greater<int>> min_q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(max_q.size()==min_q.size()){   //max q는 min q보다 원소가 같거나 1개 이상 많아야함
            max_q.push(a);
        }else{
            min_q.push(a);
        }
        if(!max_q.empty()&&!min_q.empty()&& max_q.top()>min_q.top()){     //min_q의 최솟값은 max_q의 최대값보다 커야함 
            int minvalue=min_q.top();
            int maxvalue=max_q.top();
            min_q.pop();
            max_q.pop();
            min_q.push(maxvalue);
            max_q.push(minvalue);
        }
        cout <<max_q.top()<<'\n';
    }
}