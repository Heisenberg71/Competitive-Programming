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

/**

Notes:


*/

int arr[LIM];

vector<int> nextGreater(ll n)
{
	stack<int> s;
    vector<int> result(n, n);
	for (ll i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
    return result;
}

vector<int> prevGreater(ll n)
{
	stack<int> s;
    vector<int> result(n, -1);
	for (ll i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
    return result;
}

int dp[LIM][22], log_array[LIM];  /// NEVER USE LOG/SQRT ETC. IN SIZE DECLARATION
                                            /// dp[array_size][log2(array_size)]
                                            /// dp[starting_index][range]

void construct(int n)   /// n = ARRAY SIZE; O(nlogn)
{
    log_array[1] = 0;
    for(int i = 2; i <= n; i++)
        log_array[i] = 1 + log_array[i / 2];    /// GENARATING 2 BASED LOG VALUES 1 TO n

    for(int i = 0; i < n; i++)
        dp[i][0] = arr[i];      /// SINGLE RANGE RESULTS or BASE CASE

    int k = log_array[n] + 1;

    for(int j = 1; j <= k; j++){
        for(int i = 0; i + (1 << (j - 1)) < n; i++){
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    // dp[0...n-1][1]
    // dp[0...n-1][2]
    // ...
    // dp[0...n-1][K]

}

int query(int L, int R) /// O(1)
{
    int len = R - L + 1;
    //if(len <= 0) return INT_MAX;
    int lg = log_array[len];
    return max(dp[L][lg], dp[R - (1 << lg) + 1][lg]);   /// RETURN ANSWER FROM 2 OVERLAPPING RANGES
}

int bs(int L, int R, int val)
{
    int lo = L, hi = R, md, ans = R + 1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(query(md, R) < val){
            ans = md;
            hi = md - 1;
        }
        else{
            lo = md + 1;
        }
    }
    return ans;
}

int bs2(int L, int R, int val)
{
    int lo = L, hi = R, md, ans = L - 1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(query(L, md) < val){
            ans = md;
            lo = md + 1;
        }
        else{
            hi = md - 1;
        }
    }
    return ans;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    construct(n);
    vector <int> pg = prevGreater(n), ng = nextGreater(n);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll L = pg[i], R = ng[i];
        ll L2 = bs(0, L - 1, arr[i]), R2 = bs2(R + 1, n - 1, arr[i]);

        if(pg[i] != -1) ans += (ll)arr[i]*(L - L2 + 1)*(R - i);
        if(ng[i] != n) ans += (ll)arr[i]*(i - L)*(R2 - R + 1);
    }

    cout << ans << nl;

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

