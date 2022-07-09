#include <bits/stdc++.h>
#define f first
#define s second
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef pair<int, int> pii;

/*
BFS模擬題
呃沒什麼技巧...
*/

int n, m, mode, c;
int maze[105][105];
pii way[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

void init(){
	memset(maze, 0, sizeof(maze));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			int v;
			cin >> v;
			if (!v) maze[i][j] = 0;
			else maze[i][j] = -1;
		}
	}
}

void bfs(){
	bool can_up = (mode == 1) ? true: false;
	queue <pii> q;
	for (int i=0; i<m; i++){
		if (maze[0][i] == -1){
			maze[0][i] = 1;
			q.push({0, i});
		}
	}
	while (!q.empty()){
		auto p = q.front(); q.pop();
		for (int i=0; i<4; i++){
			if (maze[p.f+way[i].f][p.s+way[i].s] == -1){
				if (i < 3 || (i == 3 && can_up)){
					maze[p.f+way[i].f][p.s+way[i].s] = maze[p.f][p.s] + 1;
					q.push({p.f+way[i].f, p.s+way[i].s});
				}
			}
		}
	}
}

void show(){
	cout << "Case " << ++c << ":\n";
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (maze[i][j] == -1) cout << 0;
			else cout << maze[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}

signed main(){
	SalAC
	
	while (cin >> mode){
		cin >> n >> m;
		init(); bfs(); show();
	}
}