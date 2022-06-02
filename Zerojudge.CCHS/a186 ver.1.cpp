#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Queue 滑窗做法
計數原理，令到第x階方法數為Step(x), 最多走k步
if x <= k, Step(x) = Step(x-1) + ... + Step(1)
if x >  k, Step(x) = Step(x-1) + ... + Step(x-k)
滑窗記錄前幾階梯的步數個數，維護滑窗內的區間和
*/

ll f(ll n){ //取餘數
	return ((n % 1000000007) + (n < 0) * 1000000007);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, total = 0;
	cin >> n >> m;
	ll dp[n]; //紀錄到每個階梯的步數
	queue <ll> sum; //開滑窗
	for (ll i=0; i<m; i++){ //滑窗元素個數小於m
		dp[i] = f(total + 1);
		total = f(total + dp[i]);
		sum.push(dp[i]);
	}
	for (ll i=m; i<n; i++){ //滑窗元素個數等於m，推入亦要彈出
		dp[i] = f(total);
		total = f(total + dp[i] - sum.front());
		sum.push(dp[i]); sum.pop();
	}
	cout << dp[n-1];
}
