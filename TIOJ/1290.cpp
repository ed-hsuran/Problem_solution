#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
Dijkstra 裸題
*/

bool flag = false;
void add_edge(vector<pii> adj[], int v1, int v2, int wgt){
	adj[v1].push_back(make_pair(v2, wgt));
	adj[v2].push_back(make_pair(v1, wgt));
}

vector <int> dijkstra(vector<pii> adj[], int n, int s){
	int inf = 1e9;
	vector<bool> visited(n, false);
	vector<int>  dis(n, inf);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	dis[s] = 0;
	pq.push(make_pair(0, s));
	
	while(!pq.empty()){
		int dot = pq.top().second;
		pq.pop();
		if (visited[dot]) continue;
		visited[dot] = true;
		for (auto i: adj[dot]){
			int tmp_dot = i.first;
			int weight = i.second;
			if (dis[tmp_dot] > dis[dot] + weight){
				dis[tmp_dot] = dis[dot] + weight;
				pq.push(make_pair(dis[tmp_dot], tmp_dot));
			}
		}
	}
	return dis;
}

int main(){
	int n, m, st, ed;
	while (cin >> n >> m >> st >> ed){
		if (flag) cout << "\n";
		st--, ed--;
		int a, b, w;
		vector<pii> adj[n];
		while(m--){
			cin >> a >> b >> w;
			a--, b--;
			add_edge(adj, a, b, w);
		}
		vector<int> ans = dijkstra(adj, n, st);
		if (ans[ed] == 1e9) cout << "He is very hot";
		else cout << ans[ed];
		flag = true;
	}
}