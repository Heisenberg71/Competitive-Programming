#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> v;
ll power(ll lim)
{
    ll ans = 1;
    while(lim--)
        ans *= 2;
    return ans;
}
ll bitmask(ll num, ll lim)
{
    ll limit = power(v.size()), i, j;
    ll ans = 0;
    for(i = 1; i < limit; i++){
        ll tem = i, mult = 1, cnt = 0;
        for(j = 0; tem; j++){
            if(tem%2){
                mult *= v[j];
                cnt++;
            }
            tem /= 2;
        }
        if(cnt%2) ans += lim/mult;
        else ans -= lim/mult;
    }
    v.clear();
    //cout << lim << " " << ans << " " << lim-ans << endl;

    return lim-ans;
}
ll phi(ll num, ll lim)
{
    ll n = num;
    for(ll i = 2; i*i <= n; i++){
        bool cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt = 1;
        }
        if(cnt) v.pb(i);
    }
    if(n != 1) v.pb(n);
//    for(ll i = 0; i < v.size(); i++)
//        cout << v[i] << " ";
//    cout << endl;
    return bitmask(num,lim);
}
int main()
{
    ll t, n, a, b, i;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        ll tot = 0;
        for(i = 2; i <= n; i++){
            ll p = (a*i)/b;
            //cout << "print: " << i << endl;
            tot += phi(i,p);
        }
        if(a == 1 and b == 1)cout << tot+2 << endl;
        else cout << tot+1 << endl;
    }
    return 0;
}
