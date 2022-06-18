#include <iostream>
using namespace std;
typedef long long ll;

/*
取餘題
給定n，求n除以任一小於等於n之五的冪次方之商數
*/

ll n;
ll p, total;

int main() {
	while (cin >> n){
		p = 5;
		total = 0;
		while(p <= n){
			total += n/p;
			p *= 5;
		}
		cout << total << endl;
	}
}