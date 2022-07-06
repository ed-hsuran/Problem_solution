#include <bits/stdc++.h>
using namespace std;

int n, m, val, ans;
vector <int> v;
vector <int> tmp;
bool f = false;

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> val;
			tmp.push_back(val);
		}
		int k = *max_element(tmp.begin(), tmp.end());
		v.push_back(k);
		ans += k;
		tmp.clear();
	}
	cout << ans << "\n";
	for (int i=0; i<v.size(); i++){
		if (ans % v[i] == 0){
			if (f) cout << " ";
			cout << v[i];
			f = true;
		}
	}
	if (!f) cout << -1;
}