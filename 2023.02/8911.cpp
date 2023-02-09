#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int direct=0;
        vector<pair<int,int>> v;
        pair<int,int> p;
        p={0,0};
        v.push_back(p);
        string s;
        cin>>s;
        int len= s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='F'&&direct==0){
                p={p.first,p.second+1};
                v.push_back(p);
            }
            else if(s[i]=='F'&&direct==1){
                p={p.first+1,p.second};
                v.push_back(p);
            }
            else if(s[i]=='F'&&direct==2){
                p={p.first,p.second-1};
                v.push_back(p);
            }
            else if(s[i]=='F'&&direct==3){
                p={p.first-1,p.second};
                v.push_back(p);
            }
            else if(s[i]=='B'&&direct==0){
                p={p.first,p.second-1};
                v.push_back(p);
            }
            else if(s[i]=='B'&&direct==1){
                p={p.first-1,p.second};
                v.push_back(p);
            }
            else if(s[i]=='B'&&direct==2){
                p={p.first,p.second+1};
                v.push_back(p);
            }
            else if(s[i]=='B'&&direct==3){
                p={p.first+1,p.second};
                v.push_back(p);
            }
            else if(s[i]=='L'&&direct==0){
                direct=3;
            }
            else if(s[i]=='L'&&direct==1){
                direct=0;
            }
            else if(s[i]=='L'&&direct==2){
                direct=1;
            }
            else if(s[i]=='L'&&direct==3){
                direct=2;
            }
            else if(s[i]=='R'&&direct==0){
                direct=1;
            }
            else if(s[i]=='R'&&direct==1){
                direct=2;
            }
            else if(s[i]=='R'&&direct==2){
                direct=3;
            }
            else if(s[i]=='R'&&direct==3){
                direct=0;
            }
        }
        int minX=v[0].first;
        int minY=v[0].second;
        int maxX=v[0].first;
        int maxY=v[0].second;
        for(int i=1;i<v.size();i++){
            if(minX>v[i].first) minX=v[i].first;
            if(minY>v[i].second) minY=v[i].second;
            if(maxX<v[i].first) maxX=v[i].first;
            if(maxY<v[i].second) maxY=v[i].second;
        }
        cout<<(maxX-minX) * (maxY-minY)<<'\n';
    }
}