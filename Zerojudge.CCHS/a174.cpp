#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

/*
滑窗 -- 但終於不是彩帶了
"先"保持窗格內總和小於k，再紀錄
*/

int n, k, v, tmp = 0, mx = 0;
pair <int, int> ans = {0, 0};
queue <int> q;

void push(int x){
	tmp += x; q.push(x);
	while (tmp > k) tmp -= q.front(), q.pop();
	if (tmp == mx) ans.s++;
	if (tmp > mx) ans = {tmp, 1};
	mx = max(mx, tmp);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> v, push(v);
	cout << ans.f << "\n" << ans.s;
}