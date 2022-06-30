#include <bits/stdc++.h>
using namespace std;

/*
二分搜
因為資料輸入完沒有要更動，用vector就好了
A集合當遍歷用不排序, B集合當詢問用(二分搜)要排序
遍歷到A[i]時，再看看有沒有一個B[i] = k - A[i]就好了
*/

int m, n, k, c;
vector <int> v1;
vector <int> v2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n >> k;
	v1.resize(m); v2.resize(n);
	for (int i=0; i<m; i++) cin >> v1[i];
	for (int i=0; i<n; i++) cin >> v2[i];
	sort(v2.begin(), v2.end());
	for (int i=0; i<m; i++){
		int tmp = *lower_bound(v2.begin(), v2.end(), k - v1[i]);
		if (tmp == k - v1[i]) c++;
	} 
	cout << c;
}