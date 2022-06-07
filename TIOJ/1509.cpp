#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define f first
#define s second
#define pb push_back
#define QIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;

/*
Dijkstra有向圖
思路:去程從哨站走到各囚室肯定沒毛病，那回程呢？
總不可能對每個囚室做一次Dijkstra
把囚室對哨站的單向回程，想成哨站對囚室的反向單向去程
簡單來說，去程Dijkstra，回程把邊反向，再Dijkstra一次
*/

vector <pii> oadj[1000001];
vector <pii> badj[1000001];

void add_edge(ll v1, ll v2, ll wgt){
	oadj[v1].pb({v2, wgt});
	badj[v2].pb({v1, wgt});
}

vector <ll> dijkstra(vector <pii> adj[], ll n, ll v){
	ll inf = 1e11;
	vector <ll>  dis(n, inf);
	vector <bool> visited(n, false);
	priority_queue <pii, vector<pii>, greater<pii> > pq;
	
	dis[v] = 0;
	pq.push({0, v});
	
	while (!pq.empty()){
		ll tmp = pq.top().s;
		pq.pop();
		if (visited[tmp]) continue;
		visited[tmp] = true;
		for (auto i: adj[tmp]){
			ll tmpv = i.f;
			ll wgt = i.s;
			if (dis[tmpv] > dis[tmp] + wgt){
				dis[tmpv] = dis[tmp] + wgt;
				pq.push({dis[tmpv], tmpv});
			}
		}
	}
	return dis;
}

int main(){
	QIO
	ll n, m, a, b, w;
	cin >> n >> m;
	while (m--){
		cin >> a >> b >> w;
		a--; b--;
		add_edge(a, b, w);
	}
	vector <ll> dis1 = dijkstra(oadj, n, 0);
	vector <ll> dis2 = dijkstra(badj, n, 0);
	bool reach = true;
	ll total = 0;
	for (int i=0; i<n; i++){
		if (dis1[i] == 1e11 || dis2[i] == 1e11){
			reach = false;
			break;
		}
		total += (dis1[i] + dis2[i]);
	}
	if (reach) cout << total;
	else cout << 0;
}