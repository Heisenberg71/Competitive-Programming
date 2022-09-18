#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

ll n, arr[LIM], MEX[LIM], cnt[LIM];
vector <ll> edge[LIM];
ordered_set os;

ll bs()
{
    ll lo = 0, hi = os.size() - 1, md, ans = os.size();
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        ll val = *os.find_by_order(md);
        if(md == val){
            lo = md + 1;
        }
        else{
            ans = md;
            hi = md - 1;
        }
    }
    return ans;
}

void dfs(ll u, ll pr)
{
    if(!cnt[ arr[u] ]) os.insert(arr[u]);
    cnt[ arr[u] ]++;
    MEX[u] = bs();

    for(ll i = 0; i < edge[u].size(); i++){
        ll v = edge[u][i];
        if(v != pr){
            dfs(v, u);
        }
    }

    cnt[ arr[u] ]--;
    if(!cnt[ arr[u] ]) os.erase(arr[u]);
}

void reset()
{
    for(ll i = 0; i <= n; i++){
        cnt[i] = 0;
        edge[i].clear();
    }
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i] > 100005) arr[i] = 100005;
    }
    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs(1, -1);

    ll mx = 0;
    for(ll i = 1; i <= n; i++)
        mx = max(mx, MEX[i]);
    cout << mx << nl;

    reset();

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. READ PROBLEM STATEMENT CAREFULLY.
    2. LOOK SPECIAL CASE (LIKE, N = 1).
    3. LOOK FOR OVERFLOW.
    4. LOOK FOR OUT OF BOUNDS.
    5. DO NOT STUCK WITH A SINGLE APPROACH.
    6. THINK OUT OF THE BOX.
**/
