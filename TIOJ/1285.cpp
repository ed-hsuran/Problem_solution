#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int n, m;

int main(){
	SalAC;
	
	while (cin >> n >> m){
		int ans = 0;
		while (n != m && n && m){
			if (n < m) swap(n, m);
			ans += n / m;
			n -= (n / m) * m;
		}
		cout << ans << "\n";
	}
}