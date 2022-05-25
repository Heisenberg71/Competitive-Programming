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

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

ll arr[LIM], dp[LIM][2];

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    ll ans = arr[0], ans2 = arr[n - 1];

    dp[1][0] = 0, dp[1][1] = arr[1];
    for(int i = 2; i < n; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i];
    }
    ans += min(dp[n - 1][0], dp[n - 1][1]);

    dp[0][0] = 0, dp[0][1] = arr[0];
    for(int i = 1; i < n - 1; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i];
    }
    ans2 += min(dp[n - 2][0], dp[n - 2][1]);

    cout << min(ans, ans2) << nl;


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
