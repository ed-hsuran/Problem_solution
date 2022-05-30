#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
Dijkstra 經典題
*/

void add_edge(vector <pii> adj[], int v1, int v2, int wgt){
	adj[v1].push_back(make_pair(v2, wgt));
	adj[v2].push_back(make_pair(v1, wgt));
}

vector<int> dijkstra(vector <pii> adj[], int n, int v){
	int inf = 1e7;
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	vector<bool> visited(n, false);
	vector<int>  dis(n, inf);
	
	pq.push(make_pair(0, v));
	dis[v] = 0;
	
	while (!pq.empty()){
		int tmp_v = pq.top().second;
		pq.pop();
		if (visited[tmp_v]) continue;
		visited[tmp_v] = true;
		
		for (auto v_data: adj[tmp_v]){
			int stretch_dot = v_data.first;
			int weight = v_data.second;
			if(dis[stretch_dot] > (dis[tmp_v] + weight)){
				dis[stretch_dot] = (dis[tmp_v] + weight);
				pq.push(make_pair(dis[stretch_dot], stretch_dot));
			}
		}
	}
	return dis;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vector <pii> adj[n];
	vector <int> data;
	int x, y, t;
	while(m--){
		cin >> x >> y >> t;
		add_edge(adj, x, y, t);
	}
	data = dijkstra(adj, n, s);
	if (data[e] == 1e7) cout << -1;
	else cout << data[e];
}