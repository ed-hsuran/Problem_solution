#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

/*
BST題
就是二元搜索，查各元素排行
我還是直接砸模板庫的紅黑樹...
改天真的要來練習自己刻自平衡二元樹ㄟ
*/

int q, k, mode, v;
tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> tr;

void output(){
	auto tmp = tr.find_by_order(k);
	if (*tmp){
		cout << *tmp << "\n";
		tr.erase(tmp); return;
	}
	cout << -1 << "\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> q >> k;
	--k;
	while (q--){
		cin >> mode;
		if (mode == 1){
			cin >> v;
			tr.insert(v);
		}
		if (mode == 2){
			output();
		}
	}
}