#include <bits/stdc++.h>
#define QIO ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

/*
RMQ基本操作--zkw線段樹
*/

const int MAXN = 500005;
ll n, arr[MAXN], zkw[MAXN<<1];

void init(ll v[]){
	for (int i=0; i<n; i++) zkw[i+n] = v[i];
	for (int i=n-1; i>0; i--) zkw[i] = max(zkw[i<<1], zkw[i<<1|1]);
}

ll query(int l, int r){
	ll ans = -1e18;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1) ans = max(ans, zkw[l++]);
		if (r & 1) ans = max(ans, zkw[--r]);
	}
	return ans;
}

int main(){
	QIO
	int q, l, r;
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	init(arr);
	cin >> q;
	while (q--){
		cin >> l >> r;
		if (l > r) swap(l, r);
		cout << query(l-1, r) << '\n';
	}
}