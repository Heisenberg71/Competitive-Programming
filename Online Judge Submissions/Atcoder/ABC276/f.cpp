#include <bits/stdc++.h>
#define ll long long
#define LIM 200000
#define mod 998244353
#define nl '\n'
using namespace std;

ll arr[LIM + 5], dp[LIM + 5], tree[4*LIM + 5], tree2[4*LIM + 5];

void update(ll st, ll ed, ll nd, ll pos, ll val)
{
    if(ed < pos || pos < st) return;
    if(st == ed){
        tree[nd] = (tree[nd] + val) %mod;
        //cout << pos << " " << nd << " " << tree[nd] << nl;
        return;
    }
    ll md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);
    tree[nd] = (tree[nd + nd] + tree[nd + nd + 1]) %mod;
}

ll query(ll st, ll ed, ll nd, ll L, ll R)
{
    if(R < st || ed < L) return 0;
    if(L <= st && ed <= R) return tree[nd];
    ll md = st + (ed - st)/2;
    return (query(st, md, nd + nd, L, R) + query(md + 1, ed, nd + nd + 1, L, R)) %mod;
}

void update2(ll st, ll ed, ll nd, ll pos, ll val)
{
    if(ed < pos || pos < st) return;
    if(st == ed){
        tree2[nd] += val;
        return;
    }
    ll md = st + (ed - st)/2;
    update2(st, md, nd + nd, pos, val);
    update2(md + 1, ed, nd + nd + 1, pos, val);
    tree2[nd] = tree2[nd + nd] + tree2[nd + nd + 1];
}

ll query2(ll st, ll ed, ll nd, ll L, ll R)
{
    if(R < st || ed < L) return 0;
    if(L <= st && ed <= R) return tree2[nd];
    ll md = st + (ed - st)/2;
    return query2(st, md, nd + nd, L, R) + query2(md + 1, ed, nd + nd + 1, L, R);
}

ll bigmod(ll a, ll b)
{
    if(!b) return 1;
    ll x = bigmod(a, b/2);
    x = (x*x) %mod;
    if(b%2) x = (x*(a%mod)) %mod;
    return x;
}

int main()
{
    ll n;

    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    update(1, LIM, 1, arr[0], arr[0]);
    update2(1, LIM, 1, arr[0], 1);
    cout << arr[0] << nl;
    for(ll i = 1; i < n; i++){
        dp[i] = (dp[i - 1] + (arr[i] + (2*query(1, LIM, 1, arr[i], LIM) + (2*arr[i]*query2(1, LIM, 1, 0, arr[i] - 1)) %mod) %mod) %mod) %mod;
        cout << (dp[i]*bigmod((i + 1)*(i + 1), mod - 2)) %mod << nl;
        update(1, LIM, 1, arr[i], arr[i]);
        update2(1, LIM, 1, arr[i], 1);
    }

    return 0;
}
