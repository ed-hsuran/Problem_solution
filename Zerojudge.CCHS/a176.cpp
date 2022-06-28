#include <bits/stdc++.h>
using namespace std;

/*
滑窗法
用Map儲存當前窗格的彩色顏色與數量
把目前map.size()紀錄，取max就是答案了
這題滑窗其實也不用開Queue
*/

int n, L, mx = 0;
int arr[200005];
unordered_map <int, int> mp; //一字千金ㄟ
// map(0.3s, 2.4MB) unordered_map(99ms, 2.6MB)

void push(int x, int y = -1){ 
	mp[x]++;
	if (y > -1) mp[y]--;
	if (!mp[y]) mp.erase(mp.find(y)); //如果要刪除的元素數量已經到0，要拔掉
	mx = max(mx, (int)mp.size());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<L; i++) push(arr[i]);
	for (int i=L; i<n; i++) push(arr[i], arr[i-L]);
	cout << mx;
}