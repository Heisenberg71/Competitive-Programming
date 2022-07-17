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
vector <int> v;

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int t, n, m, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n, greater<int>());

        double sum = 0.0, sum2 = 0.0;
        for(int i = 0; i < m - 1; i++)
            sum += arr[i];
        for(int i = m - 1; i < n; i++)
            v.pb(arr[i]);
        sort(v.begin(), v.end());

        double med;
        if(v.size()%2 == 0) med = (v[v.size()/2] + v[v.size()/2 - 1])/2.0;
        else med = v[ v.size()/2 ];

        //cout << sum << " " << med << nl;

        cout << "Case #" << cas++ << ": " << fixed << setprecision(10) << sum + med << nl;

        v.clear();
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
