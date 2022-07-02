#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
數學?
分堆後，握手問題
*/

int n, arr[4];
ll x, y, ans;

int getv(ll x, ll y){
	return ((x & 1) + 2 * (y & 1));
}

ll C(ll x){
	return ((x * (x - 1)) / 2); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> x >> y, arr[getv(x, y)]++;
	for (int i=0; i<4; i++) ans += C(arr[i]);
	cout << ans;
}