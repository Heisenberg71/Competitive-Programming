#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
using namespace std;

ll n, height[LIM], value[LIM];
ll tree[4*LIM];

ll query(ll st, ll ed, ll nd, ll L, ll R)
{
    if(ed < L || R < st) return 0;
    if(L <= st && ed <= R){
        return tree[nd];
    }

    ll md = st + (ed - st)/2;
    ll left = query(st, md, nd + nd, L, R);
    ll right = query(md + 1, ed, nd + nd + 1, L, R);

    return max(left, right);
}

void update(ll st, ll ed, ll nd, ll idx, ll val)
{
    if(idx < st || ed < idx) return;
    if(st == ed){
        tree[nd] = val;
        //cout << st << " " << val << endl;
        return;
    }

    ll md = st + (ed - st)/2;
    update(st, md, nd + nd, idx, val);
    update(md + 1, ed, nd + nd + 1, idx, val);

    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);
}

int main()
{
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> height[i];
    for(ll i = 0; i < n; i++)
        cin >> value[i];

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll val = query(1, n, 1, 1, height[i] - 1);
        //cout << val << endl;
        ans = max(ans, val + value[i]);
        update(1, n, 1, height[i], val + value[i]);
    }
    cout << ans << endl;

    return 0;
}
