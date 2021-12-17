#include <bits/stdc++.h>
#define ll long long
#define LIM 500005
using namespace std;

ll n, m, arr[LIM], brr[LIM];
ll tree[4*LIM];

void build(int st, int ed, int nd)
{
    if(st == ed){
        tree[nd] = brr[st];
        return;
    }

    int md = st + (ed - st)/2;
    build(st, md, nd + nd);
    build(md + 1, ed, nd + nd + 1);

    tree[nd] = abs(tree[nd + nd]) + abs(tree[nd + nd + 1]);
}

void update(int st, int ed, int nd, int idx, int val)
{
    //cout << st << " " << ed << " " << idx << endl;
    if(idx < st || ed < idx) return;

    if(st == ed){
        tree[nd] += val;
        //cout << "st: " << st << endl;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, idx, val);
    update(md + 1, ed, nd + nd + 1, idx, val);

    tree[nd] = abs(tree[nd + nd]) + abs(tree[nd + nd + 1]);
}

ll query(int st, int ed, int nd, int L, int R)
{
    if(ed < L || R < st) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    ll left = query(st, md, nd + nd, L, R);
    ll right = query(md + 1, ed, nd + nd + 1, L, R);

    return abs(left) + abs(right);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        brr[i] = arr[i] - arr[i - 1];

    build(0, n, 1);
    //cout << tree[1] << endl;

//    for(int i = 1; i <= n; i++)
//        cout << query(0, n, 1, i, i) << endl;
//    cout << endl;

    while(m--){
        int typ, L, R, val;
        cin >> typ;
        if(typ == 1){
            cin >> L >> R >> val;
            L--, R--;
            update(0, n, 1, L, val);
            update(0, n, 1, R + 1, -val);
        }
        else{
            cin >> L >> R;
            L--, R--;
            cout << query(0, n, 1, L + 1, R) << endl;
        }
    }

    return 0;
}
