#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int size=elements.size();
    for(int i=0;i<size-1;i++){
        elements.push_back(elements[i]);
    }
    int answer = 0;
    for(int i=1;i<=size;i++){
        int sum=0;
        int cnt=0;
        for(int j=0;j<i;j++){
            sum+=elements[j];
        }
        s.insert(sum);
        for(int j=i;j<size+i-1;j++){
            sum+=elements[j];
            sum-=elements[cnt++];
            s.insert(sum);
        }
    }
    return s.size();
}