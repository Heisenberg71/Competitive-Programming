#include <bits/stdc++.h>
#define ll long long
#define LIM 1429436
using namespace std;

int arr[LIM], tree[4*LIM];
vector <int> ans;

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

int query(int st, int ed, int nd, int L, int R)
{
    if(ed < L || R < st) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    return query(st, md, nd + nd, L, R) + query(md + 1, ed, nd + nd + 1, L, R);
}

int nextPos(int st, int diff)
{
    int lo = st, hi = LIM, md, res = -1;
    while(lo <= hi){
        int md = lo + (hi - lo)/2;
        if(query(1, LIM, 1, st, md) >= diff){
            res = md;
            hi = md - 1;
        }
        else lo = md + 1;
    }
    return res;
}

void precal()
{
    for(int i = 1; i <= LIM; i += 2)
        arr[i] = 1;

    build(1, LIM, 1);

    for(int i = 2; i <= LIM; i++){
        int diff = nextPos(1, i);
        if(diff == -1) break;
        for(int st = 1; st <= LIM; ){
            st = nextPos(st, diff);
            if(st == -1) break;
            update(1, LIM, 1, st, 0);
        }
    }
}

int main()
{
    precal();

    int t, cas = 1, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("Case %d: %d\n", cas++, nextPos(1, n));
    }

    return 0;
}
