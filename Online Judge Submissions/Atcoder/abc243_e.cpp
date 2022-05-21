#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define piii pair< pair<int, int>, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 998244353 /// changed
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

ll dp[505][505];
vector <piii> v;

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n, m;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = inf;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v.pb({{a, b}, c});
        dp[a][b] = c;
        dp[b][a] = c;
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int ans = 0;
    for(int i = 0; i < m; i++){
        bool rem = 0;
        for(int j = 0; j < n; j++){
            if(dp[ v[i].ff.ff ][j] + dp[j][ v[i].ff.ss ] <= v[i].ss)
                rem = 1;
        }
        ans += rem;
    }

    cout << ans << nl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
