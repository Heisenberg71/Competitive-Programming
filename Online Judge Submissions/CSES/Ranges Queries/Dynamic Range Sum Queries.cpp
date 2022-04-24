#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl "\n"
using namespace std;

ll arr[LIM], tree[4*LIM];

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

void update(int st, int ed, int nd, int pos, int val)
{
    if(pos < st || ed < pos) return;

    if(st == ed){
        tree[nd] = val;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

ll query(int st, int ed, int nd, int L, int R)
{
    if(R < st || ed < L) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    return query(st, md, nd + nd, L, R) + query(md + 1, ed, nd + nd + 1, L, R);

}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, n - 1, 1);

    while(q--){
        int typ, x, y;
        cin >> typ >> x >> y;
        if(typ == 1){
            update(0, n - 1, 1, x - 1, y);
        }
        else{
            cout << query(0, n - 1, 1, x - 1, y - 1) << nl;
        }
    }

    return 0;
}
