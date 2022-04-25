#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define inf 1000000009
#define nl "\n"
using namespace std;

ll arr[LIM], tree[4*LIM], lazy[4*LIM];

void build(int st, int ed, int nd)
{
    if(st == ed){
        tree[nd] = arr[st];
        return;
    }

    int md = st + (ed - st)/2;
    build(st, md, nd + nd);
    build(md + 1, ed, nd + nd + 1);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

ll query(int st, int ed, int nd, int pos)
{
    if(pos < st || ed < pos) return 0;

    if(lazy[nd] != 0){
        tree[nd] += (ed - st + 1)*lazy[nd];
        if(st != ed){
            lazy[nd + nd] += lazy[nd];
            lazy[nd + nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }

    if(st == ed) return tree[nd];

    int md = st + (ed - st)/2;
    return query(st, md, nd + nd, pos) + query(md + 1, ed, nd + nd + 1, pos);
}

void update(int st, int ed, int nd, int L, int R, int val)
{
    if(lazy[nd] != 0){
        tree[nd] += (ed - st + 1)*lazy[nd];
        if(st != ed){
            lazy[nd + nd] += lazy[nd];
            lazy[nd + nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }

    if(ed < L || R < st) return;

    if(L <= st && ed <= R){
        tree[nd] += (ed - st + 1)*val;
        if(st != ed){
            lazy[nd + nd] += val;
            lazy[nd + nd + 1] += val;
        }
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, L, R, val);
    update(md + 1, ed, nd + nd + 1, L, R, val);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
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
            int a, b, u;
            cin >> a >> b >> u;
            update(0, n - 1, 1, a - 1, b - 1, u);
        }
        else{
            int k;
            cin >> k;
            cout << query(0, n - 1, 1, k - 1) << nl;
        }
    }

    return 0;
}
