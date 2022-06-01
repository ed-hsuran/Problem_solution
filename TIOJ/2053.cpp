#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
矩陣快速冪例題
*/

struct mat{
	ll info[2][2];
	mat(){
		memset(info, 0, sizeof(info));
	}
};

mat mul(mat A, mat B, ll mod = 1e9+7){
	mat C;
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

mat pow(mat A, ll n, ll mod = 1e9){
	mat C;
	C.info[0][0] = 1; C.info[1][1] = 1;
	while (n){
		if (n & 1) C = mul(C, A);
		A = mul(A, A);
		n >>= 1;
	}
	return C;
}

int main(){
	int x1, x2, a, b, n;
	cin >> x1 >> x2 >> a >> b >> n;
	if (n == 1) cout << x1;
	if (n == 2) cout << x2;
	else{
		mat A, B;
		A.info[0][0] = x2;
		A.info[0][1] = x1;
		B.info[0][0] = b;
		B.info[0][1] = 1;
		B.info[1][0] = a;
		cout << mul(A, pow(B, n-2)).info[0][0];
	}
}