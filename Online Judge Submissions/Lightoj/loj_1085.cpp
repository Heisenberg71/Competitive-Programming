#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define mod 1000000007
using namespace std;

int n, arr[LIM], tree[4*LIM + 5];
map <int, int> idx;
set <int> s;
set <int> :: iterator it;

int query(int st, int ed, int nd, int L, int R)
{
    if(R < st || ed < L) return 0;

    if(L <= st && ed <= R) return tree[nd];

    ll md = st + (ed - st)/2;
    ll Left = query(st, md, nd + nd, L, R);
    ll Right = query(md + 1, ed, nd + nd + 1, L, R);

    return (Left + Right)%mod;
}

void update(int st, int ed, int nd, int pos, int val)
{
    if(pos < st || ed < pos) return;

    if(st == ed){
        tree[nd] = (tree[nd] + val) % mod;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);

    tree[nd] = (tree[nd + nd] + tree[nd + nd + 1])%mod;
}

ll LIS()
{
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll val = query(0, n - 1, 1, 0, idx[ arr[i] ] - 1);
        ans += val + 1; ans %= mod;
        update(0, n - 1, 1, idx[ arr[i] ], val + 1);
    }
    return ans;
}

void reset()
{
    for(int i = 0; i < 4*n + 5; i++)
        tree[i] = 0;
    idx.clear();
    s.clear();
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(ll i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            s.insert(arr[i]);
        }
        ll cnt = 0;
        for(it = s.begin(); it != s.end(); it++)
            idx[ *it ] = ++cnt;

        printf("Case %d: %lld\n", cas++, LIS());
        reset();
    }

    return 0;
}

