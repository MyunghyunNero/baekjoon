#include <string>
#include <vector>
#include <map>
using namespace std;
// 준 사람
int arr[52][52];
int giftScore[52];
map<string,int> m;
pair<string,string> split(string gift) {
    int k = 0;
    for(int i=0;i<gift.size();i++) {
        if(gift[i]==' '){
            k=i;
            break;
        }
    }
    return {gift.substr(0,k),gift.substr(k+1)};
}
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int num = 1;
    for(string f : friends) {
        m.insert({f,num});
        num++;
    }
    for(string gift : gifts) {
        pair<string,string> g = split(gift);
        arr[m[g.first]][m[g.second]]++;
    }
    for(int i=1;i<=friends.size();i++){
        int give = 0;
        for(int j=1;j<=friends.size();j++) {
            if(i==j) continue;
            give +=arr[i][j];
        }
        int take = 0;
        for(int j=1;j<=friends.size();j++) {
            if(i==j) continue;
            take +=arr[j][i];
        }
        giftScore[i] = give-take;
    }
    
    for(int i=1;i<=friends.size();i++) {
        int sum = 0;
        for(int j=1;j<=friends.size();j++) {
            if(i==j) continue;
            if(arr[i][j]>arr[j][i]) sum++;
            else if(arr[i][j]==arr[j][i] && giftScore[i]>giftScore[j]) {
                sum++;
            }
        }
        answer = max(answer,sum);
    }
    return answer;
}