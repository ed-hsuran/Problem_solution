#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

/*
區間詢問--線段樹
話說迭代型真的好用!!
就樹用pair<ll, ll>儲存，然後first存區間最大，second存區間最小
*/

int n, q, l, r;
ll arr[50005];
pll zkw[50005<<1];

void init(ll v[]){
	for (int i=0; i<n; i++) zkw[i+n] = {v[i], v[i]};
	for (int i=n-1; i>0; i--){
		auto l = zkw[i<<1];
		auto r = zkw[i<<1|1];
		zkw[i] = {max(l.f, r.f), min(l.s, r.s)};
	}
}

ll query(int l, int r){
	ll mx = -9e18;
	ll mn = 9e18;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1){
			mx = max(mx, zkw[l].f); //這邊如果寫l++會重複
			mn = min(mn, zkw[l].s);
			l++; //做完在加
		}
		if (r & 1){ //右子樹如上述
			mx = max(mx, zkw[r-1].f);
			mn = min(mn, zkw[r-1].s);
			r--;
		}
	}
	return (mx - mn);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	for (int i=0; i<n; i++) cin >> arr[i];
	init(arr);
	while (q--){
		cin >> l >> r;
		cout << query(l-1, r) << '\n';
	}
}