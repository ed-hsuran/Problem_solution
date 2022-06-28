#include <bits/stdc++.h>
using namespace std;

/*
滑窗法
用Map儲存當前窗格的彩色顏色與數量
把目前map.size()紀錄，與長度L相等，答案++
滑窗還是不用開Queue
但這題與校內站有點不一樣，彩帶的號碼數可能到10^150次方之大
所以Map的鍵用String存
*/

int L, n, c = 0;
string arr[200005];
unordered_map <string, int> mp;

void add(string x, string y = "-1"){
	mp[x]++;
	if (y != "-1") mp[y]--;
	if (!mp[y]) mp.erase(mp.find(y));
	if (L == (int)mp.size()) c++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> L >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<L; i++) add(arr[i]);
	for (int i=L; i<n; i++) add(arr[i], arr[i-L]);
	cout << c;
}