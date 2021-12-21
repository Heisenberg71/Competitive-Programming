#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
using namespace std;

int tree[4*LIM], lazy[4*LIM];

void update(int st, int ed, int nd, int L, int R, int val)
{
    if(lazy[nd] != -1){
        tree[nd] = (ed - st + 1)*lazy[nd];
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = lazy[nd];
        lazy[nd] = -1;
    }

    if(ed < L || R < st) return;

    if(L <= st && ed <= R){
        tree[nd] = (ed - st + 1)*val;
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = val;
        lazy[nd] = -1;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, L, R, val);
    update(md + 1, ed, nd + nd + 1, L, R, val);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int ed, int nd, int L, int R)
{
    if(lazy[nd] != -1){
        tree[nd] = (ed - st + 1)*lazy[nd];
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = lazy[nd];
        lazy[nd] = -1;
    }

    if(ed < L || R < st) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    int left = query(st, md, nd + nd, L, R);
    int right = query(md + 1, ed, nd + nd + 1, L, R);

    return left + right;
}

void reset(int n)
{
    for(int i = 0; i <= 4*n; i++)
        tree[i] = 0;
}

int main()
{
    int t, cas = 1, n, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &q);
        for(int i = 0; i <= 4*n; i++) lazy[i] = -1;
        printf("Case %d:\n", cas++);
        while(q--){
            int typ, L, R;
            scanf("%d %d %d", &typ, &L, &R);
            if(typ == 1){
                int val;
                scanf("%d", &val);
                update(0, n - 1, 1, L, R, val);
            }
            else{
                int range = R - L + 1;
                int sum = query(0, n - 1, 1, L, R);
                int g = __gcd(sum, range);
                range /= g, sum /= g;
                if(sum%range == 0) printf("%d\n", sum/range);
                else printf("%d/%d\n", sum, range);
            }
        }
        reset(n);
    }

    return 0;
}
