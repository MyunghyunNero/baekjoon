#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int arr[1000001];
vector<int> sequence;
int n;
void search(int num) {
    int low = 0, high = sequence.size()-1, mid;
    int ret = n;
    while (low <= high) {
        mid = (low + high) / 2;
        int here_num = sequence[mid];
        if (here_num >= num) {
            if (ret > mid)
                ret = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    sequence[ret] = num;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sequence.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(sequence.back()<arr[i]){
            sequence.push_back(arr[i]);
        }
        else{
            search(arr[i]);
        }
    }
    cout << sequence.size();
    return 0;
}
