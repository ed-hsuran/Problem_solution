#include <bits/stdc++.h>
#define QIO ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

/*
DFS--歐拉路徑
每次走訪取最小字典序之點，將DFS結果反向印出
*/

int m, i, j;
multiset <int> mp[501];
stack <int> opt;

void show(){
	while (!opt.empty()){
		cout << opt.top() << '\n';
		opt.pop();
	}
}

void dfs(int x){
	while (!mp[x].empty()){
		int idx = *mp[x].begin();
		mp[x].erase(mp[x].find(idx));
		mp[idx].erase(mp[idx].find(x));
		dfs(idx);
	}
	opt.push(x);
}

int main(){
	
	while (cin >> m){
		if (m == 0) break;
		while (m--){
			cin >> i >> j;
			mp[i].insert(j);
			mp[j].insert(i);
		}
		int first = 1;
		for (int i=1; i<501; i++){
			if (mp[i].size() & 1){
				first = i;
				break;
			}
		}
		dfs(first);
		show();
		cout << '\n';
	}
}