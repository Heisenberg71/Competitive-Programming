#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl '\n'
#define mod 1000000007
#define inf (1LL << 63)-1
#define MAXX 1000000000000015
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, grid[1005][1005];
ll rowSum[1005], colSum[1005];
vector <ll> v, temp;

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ll a, b, c;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            cin >> grid[i][j];

    cin >> a >> b >> c;
    v.pb(a), v.pb(b), v.pb(c);
    sort(v.begin(), v.end());

    for(ll i = 1; i <= n; i++){
        ll sum = 0;
        for(ll j = 1; j <= m; j++)
            sum += grid[i][j];
        rowSum[i] = rowSum[i - 1] + sum;
    }

    for(ll i = 1; i <= m; i++){
        ll sum = 0;
        for(ll j = 1; j <= n; j++)
            sum += grid[j][i];
        colSum[i] = colSum[i - 1] + sum;
    }

    ll ans = 0;

    for(ll i = 1; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            temp.pb(rowSum[i]), temp.pb(rowSum[j] - rowSum[i]), temp.pb(rowSum[n] - rowSum[j]);
            sort(temp.begin(), temp.end());
            ll f = 1;
            for(ll k = 0; k < 3; k++)
                if(temp[k] != v[k]) f = 0;
            ans += f;
            temp.clear();
        }
    }

    for(ll i = 1; i < m; i++){
        for(ll j = i + 1; j < m; j++){
            temp.pb(colSum[i]), temp.pb(colSum[j] - colSum[i]), temp.pb(colSum[m] - colSum[j]);
            sort(temp.begin(), temp.end());
            ll f = 1;
            for(ll k = 0; k < 3; k++)
                if(temp[k] != v[k]) f = 0;
            ans += f;
            temp.clear();
        }
    }

    cout << ans << endl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
