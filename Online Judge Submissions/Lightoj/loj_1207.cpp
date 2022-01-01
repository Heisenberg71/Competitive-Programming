#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
using namespace std;

int tree[4*LIM], lazy[4*LIM];
bool col[LIM];

void update(int st, int ed, int nd, int L, int R, int color)
{
    if(lazy[nd]){
        tree[nd] = lazy[nd];
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = lazy[nd];
        lazy[nd] = 0;
    }

    if(ed < L || R < st) return;

    if(L <= st && ed <= R){
        tree[nd] = color;
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = color;
        lazy[nd] = 0;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, L, R, color);
    update(md + 1, ed, nd + nd + 1, L, R, color);
}

int query(int st, int ed, int nd, int L, int R)
{
     if(ed < L || R < st) return 0;

    if(lazy[nd]){
        tree[nd] = lazy[nd];
        if(st != ed)
            lazy[nd + nd] = lazy[nd + nd + 1] = lazy[nd];
        lazy[nd] = 0;
    }

    if(L <= st && ed <= R){
        return tree[nd];
    }

    int md = st + (ed - st)/2;
    int left = query(st, md, nd + nd, L, R);
    int right = query(md + 1, ed, nd + nd + 1, L, R);

    return max(left, right);
}

void reset(int n)
{
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    memset(col, 0, sizeof col);
}

int main()
{
    int t, cas = 1, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int color = 1;
        for(int i = 0; i < n; i++){
            int L, R;
            scanf("%d %d", &L, &R);
            update(1, LIM, 1, L, R, color++);
        }
        for(int i = 1; i <= n + n; i++){
            int val = query(1, LIM, 1, i, i);
            //cout << val << " ";
            col[val] = 1;
        }
        //cout << endl;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += col[i];
        printf("Case %d: %d\n", cas++, ans);

        reset(n);
    }

    return 0;
}
