#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define inf 1000000000000000018
using namespace std;

ll LCM(ll a, ll b)
{
    return (a/__gcd(a, b))*b;
}

int main()
{
    ll t, L, R;

    cin >> t;
    while(t--){
        cin >> L >> R;
        ll ans = inf;
        for(ll g = 1; g*g <= R; g++){
            ll x = ((L + g - 1)/g)*g;
            ll y = x + g;
            if(L <= x && y <= R) ans = min(ans, LCM(x, y));
            y = ((L + g - 1)/g)*g + (L + g - 1)/g;
            if(L <= x && y <= R) ans = min(ans, LCM(x, y));
        }
        cout << ans << nl;
    }

    return 0;
}
