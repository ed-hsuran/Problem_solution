#include <bits/stdc++.h>
#define QIO ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

/*
Stack
一遇到運算子，把兩個運算元彈出來，再推回堆疊
*/

string s;
stack <int> stk;
int a, b;

bool isop(string s){
	if ((s.size() == 1) && (s == "+" || s == "-" || s == "*" || s == "/")) return true;
	return false;
}

int cal(string s){
	if (s == "+") return (a + b);
	if (s == "-") return (a - b);
	if (s == "*") return (a * b);
	if (s == "/") return (a / b);
}

int main(){
	QIO;
	while (cin >> s){
		if (isop(s)){
			b = stk.top(); stk.pop();
			a = stk.top(); stk.pop();
			stk.push(cal(s));
		}
		else stk.push(stoi(s));
	}
	cout << stk.top();
}