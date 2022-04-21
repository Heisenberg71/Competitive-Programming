#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl "\n"
#define MAXX 1000000009
using namespace std;

struct abc{
    int a, b, p;
};
map<int, int> mp;
abc arr[LIM];
vector <int> v;

bool cmp(abc x, abc y)
{
    if(x.a == y.a) x.b < y.b;
    return x.a < y.a;
}

ll tree[8*LIM];

ll query(ll st, ll ed, ll nd, ll L, ll R)
{
    if(ed < L || R < st) return 0;
    if(L <= st && ed <= R){
        return tree[nd];
    }

    ll md = st + (ed - st)/2;
    ll left = query(st, md, nd + nd, L, R);
    ll right = query(md + 1, ed, nd + nd + 1, L, R);

    return max(left, right);
}

void update(ll st, ll ed, ll nd, ll idx, ll val)
{
    if(idx < st || ed < idx) return;
    if(st == ed){
        tree[nd] = max(tree[nd], val);
        //cout << st << " " << val << endl;
        return;
    }

    ll md = st + (ed - st)/2;
    update(st, md, nd + nd, idx, val);
    update(md + 1, ed, nd + nd + 1, idx, val);

    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].p;
        if(!mp[ arr[i].a ]){
            v.pb(arr[i].a);
            mp[ arr[i].a ] = 1;
        }
        if(!mp[ arr[i].b ]){
            v.pb(arr[i].b);
            mp[ arr[i].b ] = 1;
        }
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        mp[ v[i] ] = i;
    for(int i = 0; i < n; i++){
        arr[i].a = mp[ arr[i].a ];
        arr[i].b = mp[ arr[i].b ];
    }
    sort(arr, arr + n, cmp);
//
//    for(int i = 0; i < n; i++)
//        cout << arr[i].a << " " << arr[i].b << " " << arr[i].p << nl;

    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ll val = arr[i].p + query(1, v.size(), 1, arr[i].b + 1, v.size());
        ans = max(ans, val);
        update(1, v.size(), 1, arr[i].a, val);
    }

    cout << ans << nl;

    return 0;
}
