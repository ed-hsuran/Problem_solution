#include <bits/stdc++.h>
using namespace std;

/*
取餘題
分情況討論，偶數箱子跟奇數箱子
偶數的話，走訪不相會，輸出k % n即可
奇數的話，有一排箱子都遍歷過後，有規律喔！
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n, k, step;
	cin >> t;
	while (t--){
		cin >> n >> k;
		if (!(n % 2)){
			step = k % n;
			if (!step)	cout << n;
			else cout << step;
		}
		else{
			step = (k + ((k - 1) / (n / 2))) % n;
			if (!step)	cout << n;
			else cout << step ;
		}
		cout << "\n";
	}
}