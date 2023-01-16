#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie{
	map<string, Trie*> child;
	
	void insert(vector<string> v, int depth) {
		if (depth == v.size()) return;
		string s = v[depth];
        map<string, Trie*>::iterator iter;
		iter = child.find(s);		
		if (iter != child.end()) 		
			iter->second->insert(v, depth + 1);    //해당 문자열이 있으면 다음 층으로 넘어감    
		else {
			Trie* n = new Trie;    //해당 문자열이 없으면 새로운 노드 생성후 연결
			child.insert({ s,n });
			n->insert(v, depth + 1);
		}
	}
	void dfs(int depth) {
		if (child.empty()) return;

		for (auto it = child.begin(); it != child.end(); it++) {  //child는 각 층에 있는 값들 
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << it->first << '\n';
			it->second->dfs(depth + 1);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
     cout.tie(NULL);
	int num, index;
	Trie* root = new Trie;
	string s;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> index;
		vector<string> v;
		for (int j = 0; j < index; j++) {
			cin >> s;
			v.push_back(s);
		}
		root->insert(v, 0);
	}
	root->dfs(0);
	return 0;
}