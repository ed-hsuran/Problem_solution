#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
BIT -- 逆序數對
先離散化再計數
*/

ll n, arr[100001], BIT[100001], v, ans, c = 0;
priority_queue <ll> pq;
map<ll, ll> mp;

void init(){
    mp.clear();
    for (int i=1; i<=n; i++){
        BIT[i] = 0;
        cin >> arr[i];
        pq.push(arr[i]);
    }
    for (int i=1; !pq.empty(); i++, pq.pop()) mp.insert({pq.top(), i});
}

void modify(int i){
    while (i <= n){
        BIT[i]++;
        i += (i & -i);
    }
}

ll query(int i){
    ll ans = 0;
    while (i > 0){
        ans += BIT[i];
        i -= (i & -i);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n){
        if (n == 0) break;
        init(); ans = 0;
        for (int i=1; i<=n; i++){
            ans += query(mp[arr[i]]-1);
            modify(mp[arr[i]]);
        }
        printf("Case #%d: %lld\n", ++c, ans);
    }
}