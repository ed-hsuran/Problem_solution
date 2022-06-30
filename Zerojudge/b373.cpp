#include <bits/stdc++.h>
using namespace std;

/*
BIT -- 逆序數對
不過用泡沫排序做好像就能輾過去了，而且還不用離散化
*/

int n, v, BIT[10005];
long long ans = 0;

void modify(int i){
	while (i <= n){
		BIT[i]++;
		i += (i & -i);
	}
}

int query(int i){
	int res = 0;
	while (i){
		res += BIT[i];
		i -= (i & -i);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> v;
		ans += query(n-v);
		modify(n-v+1);
	}
	cout << ans;
}