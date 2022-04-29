#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define LIM 200005
#define nl "\n"
#define ff first
#define ss second
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
using namespace std;

ll arr[LIM], tree[4*LIM], maxPrefSum[4*LIM];

void build(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd] = arr[st];
        maxPrefSum[nd] = arr[st];
        return;
    }
    build(left); /// left subtree
    build(right); /// right subtree

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
    maxPrefSum[nd] = max(maxPrefSum[nd + nd], tree[nd + nd] + maxPrefSum[nd + nd + 1]);
}

void update(int st, int en, int nd, int idx, int v)
{
    if(en < idx || idx < st) return;
    if(st == en)
    {
        tree[nd] = v;
        maxPrefSum[nd] = v;
        return;
    }
    update(left, idx, v);
    update(right, idx, v);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
    maxPrefSum[nd] = max(maxPrefSum[nd + nd], tree[nd + nd] + maxPrefSum[nd + nd + 1]);
}

pll query(int st, int en, int nd, int L, int R)
{
    if(L <= st && en <= R){
        return {tree[nd], maxPrefSum[nd]};
    }
    if(en < L || R < st){
        return {0, 0};
    }

    pll LL = query(left, L, R);
    pll RR = query(right, L, R);

    return {LL.ff + RR.ff, max(LL.ss, LL.ff + RR.ss)};
}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, n - 1, 1);

    while(q--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int k, u;
            cin >> k >> u;
            update(0, n - 1, 1, k - 1, u);
        }
        else{
            int L, R;
            cin >> L >> R;
            pll ans = query(0, n - 1, 1, L - 1, R - 1);
            cout << max(0LL, ans.ss) << nl;
        }
    }

    return 0;
}
