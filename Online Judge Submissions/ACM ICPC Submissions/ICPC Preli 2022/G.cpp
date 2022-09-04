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
#define MAXX 1000000000000000018 /// changed
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

//void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

ll n, wei[LIM], posSum, negSum, posCnt, negCnt, mx, ans;
vector <ll> edge[LIM];

void dfs(ll u, ll par, ll dist)
{
    if(dist%2 == 0){
        posCnt++;
        posSum += wei[u];
    }
    else{
        negCnt++;
        negSum += wei[u];
    }
    for(ll i = 0; i < edge[u].size(); i++){
        ll v = edge[u][i];
        if(par != v) dfs(v, u, dist + 1);
    }
}

void dfs2(ll u, ll par, ll dist)
{
    if(dist%2 == 0){
        ll val = (wei[u]*posCnt - posSum) + (negSum - wei[u]*negCnt);
        //mx = max(mx, val);
        //cout << u << " u:val " << val << nl;
        if(mx == val){
            ans = min(ans, u);
        }
        else if(mx < val){
            mx = val;
            ans = u;
        }
    }
    else{
        ll val = (posSum - wei[u]*posCnt) + (wei[u]*negCnt - negSum);
        //mx = max(mx, val);
        //cout << u << " u:val " << val << nl;
        if(mx == val){
            ans = min(ans, u);
        }
        else if(mx < val){
            mx = val;
            ans = u;
        }
    }


    for(ll i = 0; i < edge[u].size(); i++){
        ll v = edge[u][i];
        if(par != v) dfs2(v, u, dist + 1);
    }
}

void reset()
{
    for(ll i = 0; i <= n; i++){
        edge[i].clear();
        wei[i] = 0;
    }
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

//    FAST_IO();

    ll t, cas = 1;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &wei[i]);
        for(ll i = 0; i < n - 1; i++){
            ll u, v;
            scanf("%lld %lld", &u, &v);
            edge[u].pb(v);
            edge[v].pb(u);
        }

        posSum = negSum = posCnt = negCnt = 0;
        dfs(1, -1, 0);

//        cout << posSum << " " << negSum << " " << posCnt << " " << negCnt << nl;

        mx = -MAXX, ans = MAXX;
        dfs2(1, -1, 0);

        printf("Case %lld: %lld\n", cas++, ans);


        reset();
    }

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
