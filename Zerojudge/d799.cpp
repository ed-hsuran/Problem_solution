#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
線段樹--區間加值
懶標砸下去ㄅ
*/

ll n, m, l, r, v, mode;
ll arr[500005], zkw[500005<<1], lazy[500005];

void init(ll arr[]){
	for (ll i=0; i<n; i++) zkw[i+n] = arr[i];
	for (ll i=n-1; i>0; i--) zkw[i] = zkw[i<<1] + zkw[i<<1|1];
}

void update(ll i, ll h, ll v){
	zkw[i] += v << h;
	if (i < n) lazy[i] += v;
}

void push(ll i){
	for (ll h=__lg(n); h>=0; h--){
		ll tmp = i >> h;
		if (!lazy[tmp>>1]) continue;
		update(tmp, h, lazy[tmp>>1]);
		update(tmp^1, h, lazy[tmp>>1]);
		lazy[tmp>>1] = 0;
	}
}

void pull(ll i){
	for (ll h=1; i>1; i>>=1, h++){
		zkw[i>>1] = (zkw[i] + zkw[i^1]) + (lazy[i>>1]<<h);
	}
}

void modify(ll l, ll r, ll v){
	ll _l = l, _r = r, h = 0;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1, h++){
		if (l & 1) update(l++, h, v);
		if (r & 1) update(--r, h, v);
	}
	pull(_l+n);
	pull(_r+n-1);
}

ll query(ll l, ll r){
	ll ans = 0;
	push(l+n);
	push(r+n-1);
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1) ans += zkw[l++];
		if (r & 1) ans += zkw[--r];
	}
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	cin >> m;
	init(arr);
	while (m--){
		cin >> mode;
		if (mode == 1){
			cin >> l >> r >> v;
			modify(--l, r, v);
		}
		if (mode == 2){
			cin >> l >> r;
			cout << query(--l, r) << "\n";
		}
	}
}