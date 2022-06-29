#include <bits/stdc++.h>
using namespace std;

/*
滑窗法
用Map儲存當前窗格的彩色顏色與數量
把目前彩帶數量用map.size()紀錄，與長度L相等，答案++
*/

int L, n, c = 0, s;
queue <int> q;
unordered_map <int, int> mp;

void add(int x, int y = -1){
	mp[x]++; q.push(x);
	if (y > -1) mp[y]--, q.pop();
	if (!mp[y]) mp.erase(mp.find(y));
	if (L == (int)mp.size()) c++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> L >> n;
	for (int i=0; i<L; i++) cin >> s, add(s);
	for (int i=L; i<n; i++) cin >> s, add(s, q.front());
	cout << c;
}
