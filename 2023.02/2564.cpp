#include <iostream>
#include <vector>
using namespace std;
int ans;
int main(){
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin >>a>>b;
        v.push_back({a,b});
    }
    int dx,dy;
    cin>>dx>>dy;
    for(int i=0;i<n;i++){
        if(v[i].first == 1 && dx ==1){
            ans +=abs(dy-v[i].second);
        }else if(v[i].first == 1 && dx ==2){
            ans +=min(dy+y+v[i].second,y+x-dy+x-v[i].second);
        }else if(v[i].first == 1 && dx ==3){
            ans +=dy+v[i].second;
        }else if(v[i].first == 1 && dx ==4){
            ans += dy+x-v[i].second;
        }else if(v[i].first == 2 && dx ==1){
            ans +=min(dy+y+v[i].second,y+x-dy+x-v[i].second);
        }else if(v[i].first == 2 && dx ==2){
            ans +=abs(dy-v[i].second);
        }else if(v[i].first == 2 && dx ==3){
            ans +=y-dy+v[i].second;
        }else if(v[i].first == 2 && dx ==4){
            ans += y- dy+x-v[i].second;
        }else if(v[i].first == 3 && dx ==1){
            ans += v[i].second + dy;
        }else if(v[i].first == 3 && dx ==2){
            ans +=y-v[i].second + dy;
        }else if(v[i].first == 3 && dx ==3){
            ans +=abs(dy-v[i].second);
        }else if(v[i].first == 3 && dx ==4){
            ans += min(dy+x+v[i].second,x+y-dy+y-v[i].second);
        }else if(v[i].first == 4 && dx ==1){
            ans += v[i].second + x-dy;
        }else if(v[i].first == 4 && dx ==2){
            ans +=y-v[i].second + x-dy;
        }else if(v[i].first == 4 && dx ==3){
            ans +=min(dy+x+v[i].second,x+y-dy+y-v[i].second);
        }else if(v[i].first == 4 && dx ==4){
            ans += abs(dy-v[i].second);
        }
    }
    cout<<ans;
}