#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define LIM 200005
#define inf 1000000009
#define nl "\n"
using namespace std;

int price[LIM], tree[2][4*LIM];

void update(int typ, int st, int ed, int nd, int idx, int v)
{
    if(ed < idx || idx < st) return;
    if(st == ed)
    {
        tree[typ][nd] = v;
        return;
    }

    int md = st + (ed - st)/2;
    update(typ, st, md, nd + nd, idx, v);
    update(typ, md + 1, ed, nd + nd + 1, idx, v);

    tree[typ][nd] = min(tree[typ][nd + nd], tree[typ][nd + nd + 1]);
}

int query(int typ, int st, int ed, int nd, int L, int R)
{
    if(L <= st && ed <= R) return tree[typ][nd]; /// if the query segment is completely overlapping our tree segment/node.
    if(ed < L || R < st) return inf;
    int md = st + (ed - st)/2;
    return min(query(typ, st, md, nd + nd, L, R), query(typ, md + 1, ed, nd + nd + 1, L, R));
}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i  = 0; i < n; i++){
        cin >> price[i];
        //cout << price[i] << nl;
        update(0, 0, n - 1, 1, i, price[i] - i);
        update(1, 0, n - 1, 1, i, price[i] + i);
        //cout << query(0, 0, n - 1, 1, i, i) << " " << query(1, 0, n - 1, 1, i, i) << nl;
    }

    //cout << tree[0][1] << " " << tree[1][1] << nl;

    while(q--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int k, x;
            cin >> k >> x;
            k--;
            update(0, 0, n - 1, 1, k, x - k);
            update(1, 0, n - 1, 1, k, x + k);
        }
        else{
            int k;
            cin >> k;
            k--;
            cout << min(query(0, 0, n - 1, 1, 0, k) + k, query(1, 0, n - 1, 1, k + 1, n - 1) - k) << nl;
        }
    }

    return 0;
}
