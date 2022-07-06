#include <bits/stdc++.h>
using namespace std;

int n, s, i, ans;
vector <int> v;

int main(){
	cin >> n;
	while (cin >> s >> i){
		if (i > 100){
			v.push_back(s);
			ans += (i - 100) * 5;
		}
	}
    sort(v.begin(), v.end());
	for (int i: v) cout << i << " "; cout << "\n" << ans;
}