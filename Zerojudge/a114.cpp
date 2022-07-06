#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

/*
Set
把切割點丟進set，紀錄前後界差
*/

int n, L, addr, ord;
long long ans;
set <int> s;
vector <pii> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	for (int i=0; i<n; i++) cin >> addr >> ord, v.push_back({ord, addr});
	sort(v.begin(), v.end()); s.insert(0); s.insert(L);
	for (auto i: v){
		s.insert(i.second);
		ans += *(++s.find(i.second)) - *(--s.find(i.second));
	}
	cout << ans;
}