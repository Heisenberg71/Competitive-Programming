#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int n;
ll value[LIM], subTree[LIM], posSeq[LIM], tree[4*LIM];
vector <int> edge[LIM], seq;

void dfs(int u, int pr)
{
    seq.pb(u);
    subTree[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr){
            dfs(v, u);
            subTree[u] += subTree[v];
        }
    }
}

void build(int st, int ed, int nd)
{
    if(st == ed){
        tree[nd] = value[ seq[st] ];
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
    if(ed < L || R < st) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    return query(st, md, nd + nd, L, R) + query(md + 1, ed, nd + nd + 1, L, R);
}

int main()
{
    int q;

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> value[i];

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs(1, -1);
    for(int i = 0; i < seq.size(); i++)
        posSeq[ seq[i] ] = i;

    build(0, seq.size() - 1, 1);

    while(q--){
        int typ, u, x;
        cin >> typ;
        if(typ == 1){
            cin >> u >> x;
            update(0, seq.size() - 1, 1, posSeq[u], x);
        }
        else{
            cin >> u;
            cout << query(0, seq.size() - 1, 1, posSeq[u], posSeq[u] + subTree[u] - 1) << nl;
        }
    }

    return 0;
}
