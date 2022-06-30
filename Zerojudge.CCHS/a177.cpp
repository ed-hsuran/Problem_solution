#include <bits/stdc++.h>
#define pb push_back
#define sz (int)mp.size()
using namespace std;

/*
滑窗法(爬行法?) -- 彩帶好像都滑窗?
先開vector得到彩帶種類總和
開Map紀錄當前彩帶種類與數量
精髓--> 當窗格達到全彩條件，彈掉窗格的元素以縮減彩帶長度直到不符條件
*/

int n, L, arr[200005], ans = 200005;
queue <int> q;
vector <int> v;
unordered_map <int, int> mp;

void init(){
	for (int i=0; i<n; i++) cin >> arr[i], v.pb(arr[i]);
	sort(v.begin(), v.end()); //排序 
	L = distance(v.begin(), unique(v.begin(), v.end())); //扣重複 + 重塑大小
}

void push(int x){
	mp[x]++; q.push(x);
	while (sz == L){
		ans = min(ans, (int)q.size());
		int now = q.front(); q.pop();
		mp[now]--;
		if (!mp[now]) mp.erase(mp.find(now));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	init();
	for (int i=0; i<n; i++) push(arr[i]);
	cout << ans;
}
