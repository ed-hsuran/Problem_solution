#include <bits/stdc++.h>
#define sz (int)mp.size()
using namespace std;

/*
滑窗滑滑滑~
開Map紀錄當前彩帶種類與數量
當窗格紀錄到某色彩帶大於1段，彈掉窗格的元素直到該色剩1段
*/

int n, v, ans = 0;
queue <int> q;
unordered_map <int, int> mp;

void push(int x){
	mp[x]++; q.push(x);
	while (mp[x] > 1){
		int now = q.front(); q.pop();
		mp[now]--;
		if (!mp[now]) mp.erase(mp.find(now));
	}
	ans = max(ans, sz);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> v, push(v);
	cout << ans;
}