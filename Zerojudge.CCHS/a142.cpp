#include<bits/stdc++.h>
using namespace std;

/*
模逆元題
因為組合隨便用都很大，所以要考慮溢位，So!!拿出模逆元
本題的mod是質數，小費馬砸下去就對了(?
*/

long long pow(long long x, long long y, long long mod = 998244353){
	long long total = 1;
	while (y){
		if (y & 1) total = total * x % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return total;
}

long long inv(long long n, long long p){
	return pow(n, p-2, p);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, k, c = 1, mod = 998244353, total = 1;
	cin >> n >> k;
	if (k > n/2) k = n-k;
	for (int i=(n-k+1); i<(n+1); i++){
		total = (((total * i) % mod * inv(c, mod)) % mod) % mod;
		c++;
	}
	cout << total;
}