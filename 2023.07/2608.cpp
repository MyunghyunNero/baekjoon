#include <iostream>
#include <string>
#include <vector>
using namespace std;
pair<char,int> v[]={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
int vcnt[]={3,1,3,1,3,1,3};
pair<string,int> ex[]={{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
int excnt[]={3,1,1,1,3,1,1,1,3,1,1,1,3};
int changeINT(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        for(int j=6;j>=0;j--){
            if(v[j].first==s[i]){
                if(v[j].first=='I'){
                    if((i+1)<s.size() && s[i+1]=='V'){
                        sum+=4;
                        i++;
                    }else if((i+1)<s.size() && s[i+1]=='X'){
                        sum+=9;
                        i++;
                    }else{
                        sum+=1;
                    }
                }else if(v[j].first=='X'){
                    if((i+1)<s.size()&&s[i+1]=='L'){
                        sum+=40;
                        i++;
                    }else if((i+1)<s.size()&&s[i+1]=='C'){
                        sum+=90;
                        i++;
                    }else{
                        sum+=10;
                    }
                }
                else if(v[j].first=='C'){
                    if((i+1)<s.size()&&s[i+1]=='D'){
                        sum+=400;
                        i++;
                    }else if((i+1)<s.size()&&s[i+1]=='M'){
                        sum+=900;
                        i++;
                    }else{
                        sum+=100;
                    }
                }else{
                    sum+=v[j].second;
                }
                break;
            }
        }
    }
    return sum;
}
string changeStr(int num){
    string s;
    while(num!=0){
        for(int i=12;i>=0;i--){
            if(ex[i].second<=num && excnt[i]>0){
                s+=ex[i].first;
                num-=ex[i].second;
                break;
            }
        }
    }
    return s;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int ans=changeINT(s1)+changeINT(s2);
    cout<<ans<<'\n';
    cout<<changeStr(ans);

}   