#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct TRee {
    int x;
    int y;
    int idx;
    TRee *left;
    TRee *right;

};

void insert(TRee *root, TRee *child) {
    if(root->x > child->x) {
        if(root->left == NULL) {
            root->left = child;
            return;
        }
        insert(root->left,child);
    }else{
        if(root->right == NULL) {
            root->right = child;
            return;
        }
        insert(root->right,child);
    }
}
bool cmp(TRee a, TRee b) {
    if(a.y>b.y){
        return true;
    }else if(a.y==b.y) {
        if(a.x<b.x) {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
void preOrder(TRee *root, vector<int> &ans) {
    if(root ==NULL) return;
    ans.push_back(root->idx);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}
void postOrder(TRee *root, vector<int> &ans) {
    if(root == NULL) return;
    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<TRee> nodes;
    for(int i = 0;i<nodeinfo.size();i++) {
        TRee tmp = {nodeinfo[i][0],nodeinfo[i][1],i+1,NULL,NULL};
        nodes.push_back(tmp);
    }
    sort(nodes.begin(),nodes.end(),cmp);
    TRee *root = &nodes[0];
    for(int i=1;i<nodes.size();i++) {
        insert(root,&nodes[i]);
    }
    vector<int> pre;
    preOrder(root,pre);
    vector<int> post;
    postOrder(root,post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}