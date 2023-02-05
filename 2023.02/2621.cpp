#include <iostream>
#include <vector>
using namespace std;
int color[5];
int cnt[10];
int main(){
    for(int i=0;i<5;i++){
        char a;
        int b;
        cin>>a>>b;
        if(a=='R'){
            color[0]++;
        }else if(a=='B'){
            color[1]++;
        }else if(a=='Y'){
            color[2]++;
        }else{
            color[3]++;
        }
        cnt[b]++;
    }
    int ans=0;
    int colorOne=0,colorTwo=0,colorThree=0,colorFour=0,colorFive=0;
    for(int i=0;i<4;i++){
        if(color[i]==1) colorOne++;
        if(color[i]==2) colorTwo++;
        if(color[i]==3) colorThree++;
        if(color[i]==4) colorFour++;
        if(color[i]==5) colorFive++;
    }
    int yes = 0, maxNum = -1;
    for (int i = 1; i <= 6; i++) {
        if (cnt[i] == 1 && cnt[i + 1] == 1 && cnt[i + 2] == 1 && cnt[i + 3] == 1 && cnt[i + 4] == 1) yes = 1;
    }

    int n_one = 0, n_two = 0, n_three = 0, n_four = 0, n_five = 0, i_four = 0, i_three = 0;
    int i_two[2];
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0) maxNum = i;
        if (cnt[i] == 1) n_one++;
        else if (cnt[i] == 2) {
            n_two++;
            if (n_two == 1)i_two[0] = i;
            else i_two[1] = i;
        }
        else if (cnt[i] == 3) {
            n_three++;
            i_three = i;
        }
        else if (cnt[i] == 4) {
            n_four++;
            i_four = i;
        }
        else if (cnt[i] == 5) n_five++;
    }

    //카드 5장이 모두 같은 색이면서 숫자가 연속적일 때, 점수는 가장 높은 숫자에 900을 더한다. 예를 들어, 카드가 Y4, Y3, Y2, Y5, Y6 일 때 점수는 906(=6+900)점이다.
    if (colorFive == 1 && yes == 1) ans = maxNum + 900;
    //카드 5장 중 4장의 숫자가 같을 때 점수는 같은 숫자에 800을 더한다. 예를 들어, 카드가 B3, R3, B7, Y3, G3 일 때 점수는 803(=3+800)점이다.
    else if (n_four == 1) ans = 800 + i_four;
    //카드 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 점수는 3장이 같은 숫자에 10을 곱하고 2장이 같은 숫자를 더한 다음 700을 더한다. 예를 들어, 카드가 R5, Y5, G7, B5, Y7 일 때 점수는 757(=5x10+7+700)점이다.
    else if (n_three == 1 && n_two == 1)  ans = (i_three * 10) + i_two[0] + 700;
    //5장의 카드 색깔이 모두 같을 때 점수는 가장 높은 숫자에 600을 더한다. 예를 들어, 카드가 Y3, Y4, Y8, Y6, Y7 일 때 점수는 608(=8+600)점이다.
    else if (colorFive == 1) ans = maxNum + 600;
    //카드 5장의 숫자가 연속적일 때 점수는 가장 높은 숫자에 500을 더한다. 예를 들어 R7, R8, G9, Y6, B5 일 때 점수는 509(=9+500)점이다.
    else if (yes == 1) ans = maxNum + 500;
    //카드 5장 중 3장의 숫자가 같을 때 점수는 같은 숫자에 400을 더한다. 예를 들어 R7, Y7, R2, G7, R5 일 때 점수는 407(=7+400)점이다.
    else if (n_three == 1) ans = i_three + 400;
    //카드 5장 중 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 점수는 같은 숫자 중 큰 숫자에 10을 곱하고 같은 숫자 중 작은 숫자를 더한 다음 300을 더한다. 예를 들어, R5, Y5, Y4, G9, B4 일 때 점수는 354(=5X10+4+300)점이다.
    else if (n_two == 2) ans = (max(i_two[0], i_two[1]) * 10) + min(i_two[0], i_two[1]) + 300;
    //카드 5장 중 2장의 숫자가 같을 때 점수는 같은 숫자에 200을 더한다. 예를 들어, R5, Y2, B5, B3, G4 일 때 점수는 205(=5+200)점이다.
    else if (n_two == 1) ans = i_two[0] + 200;
    //위의 어떤 경우에도 해당하지 않을 때 점수는 가장 큰 숫자에 100을 더한다. 예를 들어, R1, R2, B4, B8, Y5 일 때 점수는 108(=8+100)점이다.
    else ans = maxNum + 100;

    cout<<ans;
}