#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back 
#define QIO ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef pair<int, int> pii;

/*
Dijkstra (感謝明達學長)
關鍵:單點對所有點最短路徑 -> 所有點到單點最短路徑
起點s終點e各做一次Dijkstra，枚舉每一條{u, v}當作使用超時空隧道，計算最短dis(s, u) + dis(v, e)
*/

vector <int> dijkstra(vector <pii> adj[], int n, int v){
	int inf = 1e8;
	vector <int> dis(n, inf);
	vector <bool> visited(n, false);
	priority_queue <pii, vector<pii>, greater<pii> > pq;

	dis[v] = 0;
	pq.push({0, v});
	while (!pq.empty()){
		int v = pq.top().s;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;
		for (auto data: adj[v]){
			int tmp_v = data.f;
			int wgt = data.s;
			if (dis[tmp_v] > dis[v] + wgt){
				dis[tmp_v] = dis[v] + wgt;
				pq.push({dis[tmp_v], tmp_v});
			}
		}
	}
	return dis;
}

int main() {
	QIO
	int n, m, s, e;
	int a, b, w;
	cin >> n >> m >> s >> e;
	vector <pii> adj[n];
	vector <pii> edge;
	for (int i=0; i<m; i++){
		cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
		edge.pb({a, b});
		edge.pb({b, a});
	}
	int shortest = 1e9;
	vector <int> sd = dijkstra(adj, n, s);
	vector <int> ed = dijkstra(adj, n, e);
	while (!edge.empty()){
		auto data = edge.back();
		edge.pop_back();
		shortest = min(shortest, sd[data.f] + ed[data.s]);
	}
	if  (shortest >= 1e8) cout << -1;
	else cout << shortest;
}