#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct mat{
	
	ll info[101][101];
	
	mat(){
		memset(info, 0, sizeof(info));
	}
	
	void iden(ll n){
		for (int i=0; i<n; i++){
			info[i][i] = 1;
		}
	}
};

mat mul(mat A, mat B, ll n, ll mod = 1e9+7){
	mat C;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				C.info[i][j] += ((A.info[i][k] % mod) * (B.info[k][j] % mod) % mod);
				C.info[i][j] %= mod;
			}
		}
	}
	return C;
}

mat pow(mat A, ll p, ll n, ll mod = 1e9+7){
	mat C;
	C.iden(n);
	while (p){
		if (p & 1) C = mul(C, A, n);
		A = mul(A, A, n);
		p >>= 1;
	}
	return C;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	ll total = 0;
	mat A, B;
	cin >> n >> m;
	for (int i=0; i<m; i++){
		A.info[0][m-i-1] = total + 1;
		total += A.info[0][m-i-1];
	}
	for (int i=0; i<m; i++){
		B.info[i][0] = 1;
		B.info[i][i+1] = 1;
	}
	B = pow(B, n-m, m);
	cout << mul(A, B, m).info[0][0];
}