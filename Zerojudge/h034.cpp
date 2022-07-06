#include <bits/stdc++.h>
using namespace std;

int n, mx;
string s;
vector <int> sz;
vector <string> v;

bool ch(char c){
	int v = c - '0';
	if (v > -1 && v < 10) return true;
	return false;
}

int main(){
	cin >> n;
	while (cin >> s){
		sz.push_back(s.size());
		v.push_back(s);
		mx = max(mx, (int)s.size());
	}
	for (int i=0; i<mx; i++){
		for (int j=0; j<n; j++){
			if (sz[j] > i && !ch(v[j][i])) cout << v[j][i];
		}
	}
}