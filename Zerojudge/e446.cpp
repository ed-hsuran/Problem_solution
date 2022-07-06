#include <bits/stdc++.h>
using namespace std;

/*
遞迴練習
不過這題直接用next_permutation
(7.7s)，如果把資料推進vector再清空會更快
*/

int n;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++){
		v.push_back(i);
	}
	do{
		for (int i=0; i<n; i++) cout << v[i] << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}