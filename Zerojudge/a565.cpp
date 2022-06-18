#include <iostream>
using namespace std;

/*
Stack概念
不過就用變數儲存未被配對的p的個數就好了
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int p, count;
	string s, v;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> s;
		count = 0;	p = 0;
		for (int j=0; j<s.size(); j++){
			if (s[j] == 'p'){
				p++;
			}
			else if (s[j] == 'q' && p > 0){
				count++;
				p--;
			}
		}
	cout << count << endl;
	}
}
