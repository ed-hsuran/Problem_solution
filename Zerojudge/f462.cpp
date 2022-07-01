#include <bits/stdc++.h>
#define str string
#define add() Trie.push_back(node{}) //開新記憶
using namespace std;

/*
字典樹(Debug 2...hr)
顧名思義先種一棵字典樹
我的方法是種的過程紀錄葉節點
Shortest name就從葉節點爬上去，遇到根或LCA就記錄當前字串長度
*/

struct node{
	int cnt; //目前字串階層(長度)
	int f_addr; //父節點
	unordered_map <int, int> child;
	//字典樹(26元)太虧 {字元種類, 該字元在vector的位置}
};

int top; //紀錄節點開到哪了
vector <node> Trie; //採偽指標儲存
vector <int> leaf; 

void insert(str s){
	int i = 0;
	int cnt_ = 0;
	for (char c: s){
		cnt_++; //字串階層
		if (!Trie[i].child[c-'a']){
			Trie[i].child[c-'a'] = top;
			Trie[top].cnt = cnt_;
			Trie[top].f_addr = i;
			i = top;
			top++; add();
		}
		else i = Trie[i].child[c-'a'];
	}
	leaf.push_back(i);
}

int t, n, ans;
str s;

void init(){ //每次結束重置函式
	top = 1; ans = 0;
	Trie.clear(); add(); add();
	leaf.clear();
	Trie[0].f_addr = -1;
}

void collect(int i){ //葉節點上爬
	while ((int)Trie[Trie[i].f_addr].child.size() == 1 && Trie[i].f_addr){
		//判斷式 -> (該節點父親只有它一個小孩 && 不是根節點)
		i = Trie[i].f_addr;
	}
	ans += Trie[i].cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		init();
		while (n--){
			cin >> s;
			insert(s);
		}
		for (int i: leaf) collect(i);
		cout << ans << "\n";
	}
}