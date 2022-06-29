#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
質數模逆元 -- 小費馬
建快速冪算 a^(p-2) (mod p)即可
*/

ll n, p, v;

ll pow(ll x, ll n, ll p){
	ll ans = 1;
	while (n){
		if (n & 1) ans = (ans * x) % p;
		x = (x * x) % p;
		n >>= 1;
	}
	return (ans % p);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> p;
	while (n--){
		cin >> v;
		cout << pow(v, p-2, p) << " ";
	}
}