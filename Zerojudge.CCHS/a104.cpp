#include <bits/stdc++.h>
#include <bits/extc++.h>
#define QIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;

/*
我覺得BST題啦(?
簡單來說就是每個人的X+Y前面有幾個人X比他小的總和
我原本要用multiset...但是沒辦法得出某人是第幾號...
所以我用pbds(Policy-Base Data Structure)的紅黑樹(rb_tree), 有點太好用...
*/

int n;
ll total = 0;
ld arr[300005], pot, c = 0;
tree<ld, null_type, less<ld>, rb_tree_tag, tree_order_statistics_node_update> tr;

void push(ld x){ //因為樹不能插入重複值
	if (tr.find(x) != tr.end()){
		c += 0.000000001; //把變數存成long double, 當作其他值在兩整數之間
		x += c;
	}
	tr.insert(x);
}

int main() {
	QIO
	
	tr.insert(0); tr.insert(9e18);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<n; i++){
		cin >> pot;
		auto idx = --tr.lower_bound(arr[i] + pot);
		//找第一個大於等於這個人的魔力在哪個位置
		total += max((ld)0, (ld)(tr.order_of_key(*idx)));
		//所以往前推一格元素的排名就是它能超越的總數
		push(arr[i]);
	}
	cout << total;
}