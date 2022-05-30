#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back 
using namespace std;
typedef pair<int, int> pii;

/*
Dijkstra (還是感謝明達學長 Orz)
關鍵:疊圖分析，開2n紀錄點
每推入一個邊adj[u].pb({v, dis}), adj[v].pb({u, dis}), 多推入
adj[a]  .pb({b+n, 0})  , adj[b]  .pb({a+n, 0});   ({a, b}使用超時空隧道)
adj[a+n].pb({b+n, dis}), adj[b+n].pb({a+n, dis}); (使用隧道後的走訪)
最後對得到的圖做一次dijkstra
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
	int n, m, s, e;
	int a, b, w;
	cin >> n >> m >> s >> e;
	vector <pii> adj[n*2];
	for (int i=0; i<m; i++){
		cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
		adj[a].pb({b+n, 0});
		adj[b].pb({a+n, 0});
		adj[a+n].pb({b+n, w});
        adj[b+n].pb({a+n, w});
	}
	vector <int> data = dijkstra(adj, 2*n, s);
	int ans = data[e+n];
	if (ans >= 1e8) cout << -1;
	else cout << ans;
}