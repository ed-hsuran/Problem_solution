#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
矩陣快速冪
| x2 x1 | * | b 1 | = | f(n) f(n-1) |
|  0  0 |   | a 0 |   |   0     0   |
*/

struct matrix{
	
	ll info[2][2];
	
	void init(){
		memset(info, 0, sizeof(info));
	}
	
	void iden(){
		for (int i=0; i<2; i++){
			for (int j=0; j<2; j++){
				if (i == j) info[i][j] = 1;
				else info [i][j] = 0;
			}
		}
	}
};

matrix mul(matrix A, matrix B, ll mod = 1e9+7){
	matrix C;
	C.init();
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<2; k++){
				C.info[i][j] += ((A.info[i][k] % mod) * (B.info[k][j] % mod)) % mod;
				C.info[i][j] %= mod;
			}
		}
	}
	return C;
}

matrix pow(matrix A, ll n, ll mod = 1e9+7){
	matrix C;
	C.iden();
	while (n){
		if (n & 1) C = mul(C, A, mod);
		A = mul(A, A, mod);
		n = n >> 1;
	}
	return C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x1, x2, a, b, n;
	matrix A, B, C;
	A.init(); B.init(); C.init();
	while (cin >> x1 >> x2 >> a >> b >> n){
		if (n == 1){
			cout << x1 << "\n";
			continue;
		}
		if (n == 2){
			cout << x2 << "\n";
			continue;
		}
		A.info[0][0] = x2;
		A.info[0][1] = x1;
		B.info[0][0] = b;
		B.info[0][1] = 1;
		B.info[1][0] = a;
		C = mul(A, pow(B, n-2));
		cout << C.info[0][0] << "\n";
	}
}