#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

vector <ll> fac;

void fact(ll n)
{
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            fac.pb(i);
            if(i != n/i) fac.pb(n/i);
        }
    }
}

bool isPal(ll num)
{
    string str, temp;
    while(num){
        str += '0' + num%10;
        num /= 10;
    }
    temp = str;
    reverse(str.begin(), str.end());
    return (str == temp);
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    ll t, n, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        fact(n);
        ll cnt = 0;
        for(ll i = 0; i < fac.size(); i++){
            if(isPal(fac[i])) cnt++;
        }
        //cout << cnt << nl;
        printf("Case #%lld: %lld\n", cas++, cnt);

        fac.clear();
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
