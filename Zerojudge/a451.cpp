#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
矩陣快速冪模板題
注意邊界case...我被卡了4次TLE(3s)
結果34ms就輾過去了...
*/

struct mat{
	
	ll info[2][2];
	mat(){ 
		memset(info, 0, sizeof(info));
	}
	
	void iden(){ 
		info[0][0] = 1;
		info[1][1] = 1;
	}
};

mat mul(const mat &A, const mat &B, const ll &mod){ 
	mat C;
	for(int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<2; k++){
				C.info[i][j] = (A.info[i][k] * B.info[k][j] + C.info[i][j]) % mod;
			}
		}
	}
	return C;
}

mat mpow(mat A, int n, ll &mod){ 
	mat C;
	C.iden();
	while (n){
		if (n & 1) C = mul(A, C, mod);
		A = mul(A, A, mod);
		n = n >> 1;
	}
	return C;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	while (cin >> n >> m){
		if (n == 0){
			cout << "0\n";
			continue;
		}
		if (n == 1){
			cout << "1\n";
			continue;
		}
		mat A, B;
		ll mod = 1 << m;
		A.info[0][0] = 1;
		A.info[0][1] = 1;
		B.info[0][0] = 1;
		B.info[0][1] = 1;
		B.info[1][0] = 1;
		B = mpow(B, n-2, mod);
		cout << mul(A, B, mod).info[0][0] << '\n';
	}
}