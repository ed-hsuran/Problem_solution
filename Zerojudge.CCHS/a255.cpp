#include <bits/stdc++.h>
using namespace std;

/*
矩陣乘法
令矩陣乘式 -> A * B = C
A 為 a*b 之矩陣, B 為 p*q 之矩陣, 得
C 為 a*q 之矩陣
*/

struct matrix{
	
	int info[505][505];

	void init(){
		memset(info, 0, sizeof(info));
	}
	
	void show(int r, int c){
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				cout << info[i][j] << ' ';
			}
		cout << '\n';
		}
	}
};

matrix mul(matrix A, matrix B, int n, int m, int depth){ // n = a, m = q, depth = (b or c)
	matrix C;
	C.init();
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			for (int k=0; k<depth; k++){
				C.info[i][j] += A.info[i][k] * B.info[k][j];
			}
		}
	}
	return C;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, p, q, tmp;
	cin >> a >> b >> p >> q;
	matrix A, B, C;	
	A.init(); B.init(); C.init();
	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			cin >> tmp;
			A.info[i][j] = tmp;
		}
	}
	for (int i=0; i<p; i++){
		for (int j=0; j<q; j++){
			cin >> tmp;
			B.info[i][j] = tmp;
		}
	}
	C = mul(A, B, a, q, b);
	C.show(a, q);
}