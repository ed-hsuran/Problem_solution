#include <bits/stdc++.h>
using namespace std;

/*
Greedy核心 --> 順便練練bitset吧
由左開始翻煎餅，遇到需要翻的煎餅，紀錄位置
記得 紀錄的位置+k > 指針，要pop掉
*/

int n, k, c = 0;
bool access = true;
string tmp;
queue <int> flip;
bitset<1000005> s;

bool check(int i){ //奇數次代表相較原狀態會被翻面，偶數反之
	return (s[i] + flip.size() & 1);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k >> tmp;
	for (int i=0; i<n; i++){
		if (tmp[i] == 'o') s[i] = 1;
		if (tmp[i] == 'x') s[i] = 0;
	}
	for (int i=0; i<=n-k; i++){
		if (!check(i)){
			c++;
			flip.push(i+k-1);
		}
		if (flip.size() && flip.front() == i) flip.pop();
	}
	for (int i=n-k+1; i<n; i++){
		if (!check(i)){
			access = false;
			break;
		}
		if (flip.size() && flip.front() == i) flip.pop();
	}
	cout << (access ? c : -1);
}