#include <iostream>
using namespace std;
typedef long long ll;

/*
二維陣列操作題?
想法: From. 莊大電神
以地圖每個點為maze[i][j]
從終點maze[n][m]做回來，只要找到一點使其上點與左點相同即存在路徑
*/

int n, a, b;
int maze[105][105];

void get(){ //輸入地圖不用管它...
	int tmp;
	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			cin >> maze[i][j];
		}
	}
}

bool sweep(){ //遍歷
	for (int i=a-1; i>0; i--){
		for (int j=b-1; j>0; j--){
			if (maze[i][j-1] == maze[i-1][j]) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while (n--){
		cin >> a >> b;
		get();
		if (sweep()) cout << "Yes\n";
		else cout << "No\n";
	}
}