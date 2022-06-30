#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

/*
滑窗 & 單調隊列
xy關係看成(位置, 值) -> 用pair綁在一起
以x排序後，維護窗格內的值在大小為之L區間內
*/

int n, L, ans;
vector <pii> v;
deque <pii> mxst;
deque <pii> mnst;

void init(){
	for (int i=0; i<n; i++)	cin >> v[i].f;
	for (int i=0; i<n; i++) cin >> v[i].s;
	sort(v.begin(), v.end());
}

void push(pii x){
	while (!mxst.empty() && x.f - mxst.back().f > L) mxst.pop_back();
	while (!mnst.empty() && x.f - mnst.back().f > L) mnst.pop_back();
	while (!mxst.empty() && x.s > mxst.front().s) mxst.pop_front();
	while (!mnst.empty() && x.s < mnst.front().s) mnst.pop_front();
	mxst.push_front(x); mnst.push_front(x);
	ans = max(ans, mxst.back().s - mnst.back().s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	v.resize(n); init();
	for (auto i: v) push(i);
	cout << ans;
}