#include <bits/stdc++.h>
#define ppf pop_front
#define ppb pop_back
#define puf push_front
#define pub push_back
#define ept empty
using namespace std;

/*
滑窗Deque -- 固定區間極值
這題就維護兩個單調隊列(max, min)
紀錄當前窗格最大最小值的差
*/

int n, L, ans = 0;
int arr[200005];
deque <int> mxst;
deque <int> mnst;

void push(int x, int y = (int)1e9+5){
	if (!mxst.ept() && y == mxst.back()) mxst.ppb();
	if (!mnst.ept() && y == mnst.back()) mnst.ppb();
	while (!mxst.ept() && x > mxst.front()) mxst.ppf();
	while (!mnst.ept() && x < mnst.front()) mnst.ppf();
	mxst.puf(x); mnst.puf(x);
	ans = max(ans, mxst.back() - mnst.back());
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<L; i++) push(arr[i]);
	for (int i=L; i<n; i++) push(arr[i], arr[i-L]);
	cout << ans;
}