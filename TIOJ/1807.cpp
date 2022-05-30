#include <bits/stdc++.h>
using namespace std;

/*
Map + Set做法
簡單圖不可含重邊跟自環
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long v, e, v1, v2;
	cin >> v >> e;
	map<int, set<int>> G;
	while (e--){
		cin >> v1 >> v2;
		v1--, v2--;
		if (v1 > v2) swap(v1, v2);
		if (v1 == v2 || G[v1].count(v2)){
			cout << "Yes";
			return 0;
		}
		G[v1].insert(v2);
	}
	cout << "yes";
}