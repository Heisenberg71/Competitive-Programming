#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

int arr[LIM];
vector <pii> v;

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int min2 = inf, min3 = inf;
    for(int i = 0; i < n; i++){
        int cnt2 = 0, cnt3 = 0;
        while(arr[i]%2 == 0){
            arr[i] /= 2;
            cnt2++;
        }
        while(arr[i]%3 == 0){
            arr[i] /= 3;
            cnt3++;
        }
        v.pb({cnt2, cnt3});
        min2 = min(min2, cnt2);
        min3 = min(min3, cnt3);
    }

    for(int i = 1; i < n; i++){
        if(arr[0] != arr[i]){
            cout << -1 << nl;
            return 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += v[i].ff - min2 + v[i].ss - min3;
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

