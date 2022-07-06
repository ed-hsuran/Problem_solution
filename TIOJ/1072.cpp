#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

/*
Greedy
依吃飯時間排序
*/

int n, a, b, ans, eat;
priority_queue <pii> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (cin >> n){
	ans = 0; eat = 0;
		while (n--){
			cin >> a >> b;
			pq.push({b, a});
		}
		while (!pq.empty()){
			pii now = pq.top(); pq.pop();
			eat = max(max(eat - now.s, 0), now.f);
			ans += now.s;
		}
		cout << eat + ans << "\n";
	}
}