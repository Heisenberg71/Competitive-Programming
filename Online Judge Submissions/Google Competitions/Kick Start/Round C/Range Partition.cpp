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



int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    ll t, n, cas = 1;
    cin >> t;
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        printf("Case #%d: ", cas++);
        ll sum = (n*(n + 1))/2;
        if(sum % (x + y) != 0){
            cout << "IMPOSSIBLE" << nl;
        }
        else{
            cout << "POSSIBLE" << nl;
            ll xx = (sum*x)/(x + y);
            ll yy = (sum*y)/(x + y);

            vector <ll> ans;
            for(ll i = n; i > 0; i--){
                if(xx >= i){
                    ans.pb(i);
                    xx -= i;
                }
            }
            cout << ans.size() << nl;
            for(ll i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << nl;
        }
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
