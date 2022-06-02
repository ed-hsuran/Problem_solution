#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
矩陣快速冪
關鍵:依極限步數開出m * m的方陣, 而且做冪次的那個方陣有規律
然後題敘寫到 1 < m <= 500, m = (n, 500);
不過因為學校測資機的記憶體...開到505 * 505就core dumped了
*/

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
	for (int i=0; i<m; i++){ // A矩陣
		A.info[0][m-i-1] = total + 1;
		total += A.info[0][m-i-1];
	}
	for (int i=0; i<m; i++){ // B矩陣, 做冪次的那個
		B.info[i][0] = 1;
		B.info[i][i+1] = 1;
	}
	B = pow(B, n-m, m);
	cout << mul(A, B, m).info[0][0];
}