#include <iostream>
using namespace std;
typedef long long ll;

/*
算梗題?
因為必有一時間點使建設性干涉情況最多成立...
時間設無限大到，讓每個波源輻散出的波皆與其他波源有交點
簡單來說
C n取2 * 2(每兩個波源的交點數) = P n取2
*/

int n, m;

int main(){
	cin >> n >> m;
	ll ans = (ll)n * (ll)(n-1);
	cout << ans;
}