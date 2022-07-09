#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair <int, int> pii;

int n, vk, q, ans;
int a, b, w;
vector <pii> G[5005];
vector <bool> visited(5005, false);

void dfs(int v, int mn = 1000000005){
	visited[v] = true;
	for (auto i: G[v]){
		if (!visited[i.f]){
			if (min(mn, i.s) >= q) ans++;
			dfs(i.f, min(mn, i.s));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> vk >> q;
	for (int i=0; i<n-1; i++){
		cin >> a >> b >> w;
		G[a].pb({b, w});
		G[b].pb({a, w});
	}
	dfs(vk);
	cout << ans;
}