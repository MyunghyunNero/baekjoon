#include <iostream>
#include <vector>
using namespace std;
int sdq[9][9];

int go(vector<int>& blank,int i,int len){
    bool check1[10]={0};
    bool check2[10]={0};
    bool check3[10]={0};
    vector<int> v;
    if(i==len){
        return 1;
    }
    int row=blank[i]%9;         //빈공간 열위치
    int col=blank[i]/9;          //빈공간 행위치
    for(int k=0;k<9;k++){
        check1[sdq[col][k]]=true;    //빈공간 열에 있는 값 true
    }
    for(int k=0;k<9;k++){
        check2[sdq[k][row]]=true;      //빈공간 행에 있는 값 true
    }
    int squrow=(row/3)*3;
    int squcol=(col/3)*3;
    for(int k=squcol;k<squcol+3;k++){       //빈공간이 속해있는 3*3 공간 값 true
        for(int j=squrow;j<squrow+3;j++){
            check3[sdq[k][j]]=true;
        }
    }
    for(int k=1;k<10;k++){
        if(check1[k]==false&&check2[k]==false&&check3[k]==false){     //공통적으로 없는 값 넣기
            v.push_back(k);
        }
    }
    if(v.empty()){           //공통적으로 없는 값이 없으면 즉  답이 나올 수 없으면 0리턴
        return 0;
    }
    int vlen=v.size();
    for(int k=0;k<vlen;k++){
        sdq[col][row]=v[k];          //공통적으로 없는 값 넣어보기
        int suc=go(blank,i+1,len);
        if(suc==1){                  //성공하면 리턴 1반환
            return 1;
        }else{
            sdq[col][row]=0;               //실패시 원상복구
        }
    }  
    return 0;                            //다 검색해도 안나오면 0리턴
    
}
int main(){
    vector<int> blank;
    for(int i=0;i<9;i++){
        for(int k=0;k<9;k++){
            cin>>sdq[i][k];
            if(sdq[i][k]==0){
                blank.push_back(i*9+k);
            }
        }
    }
    int len=blank.size();
    go(blank,0,len);
    for(int i=0;i<9;i++){
        for(int k=0;k<9;k++){
            cout<<sdq[i][k]<<' ';
        }
        cout<<'\n';
    }
}