#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

/*
快速冪練習
不過有一點值得注意，多項式我沒找到單位元素
先設初始值，直到一個位元為1再重新賦值
*/

int x, y, n;

ll f(ll x) {return (x % 1000000009);}

pll mul(pll a, pll b){
	ll x_ = f(a.x * b.x) + f(a.y * b.y << 1);
	ll y_ = f(a.x * b.y) + f(a.y * b.x);
	return {f(x_), f(y_)};
}

pll pow(pll x, int n){
	pll res = {0, 0};
	while (n){
		if (n & 1){
			if (!res.x && !res.y) res = x;
			else res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

int main(){
	cin >> x >> y >> n;
	pll ans = pow({x, y}, n);
	printf("%d %d", ans.x, ans.y);
}