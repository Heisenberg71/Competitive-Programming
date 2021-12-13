#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mod 10000019
#define LIM 100000
using namespace std;
bool status[LIM+5];
vector <ll> v;
vector <pair<ll,ll> > prime_pow;
void make_prime()
{
    ll i, j;

    status[0] = status[1] = 1;
    for(i = 4; i <= LIM; i += 2)
        status[i] = 1;

    for(i = 3; i*i <= LIM; i++){
        if(!status[i]){
            for(j = i*i; j <= LIM; j += i+i)
                status[j] = 1;
        }
    }

    for(i = 0; i <= LIM; i++)
        if(!status[i]) v.pb(i);
}
ll bigmod(ll a, ll b)
{
    if(!b) return 1;
    ll x = bigmod(a,b/2);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}
int main()
{
    make_prime();
    ll t, n, i, tz, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> tz;
        for(i = 0; v[i] <= n; i++){
            ll tem = v[i], cnt = 0;
            while(tem <= n){
                cnt += n/tem;
                tem *= v[i];
            }
            prime_pow.pb({v[i],cnt});
        }
//        for(i = 0; i < prime_pow.size(); i++)
//            cout << prime_pow[i].ff << " " << prime_pow[i].ss << endl;
        ll ans = 1, f = 0; //cout << "stuck" << endl;
        for(i = 0; i < prime_pow.size(); i++){
            ll pow = 1;
            while(prime_pow[i].ss/pow >= tz)
                pow++, f = 1;
            pow--;
            ans *= bigmod(prime_pow[i].ff,pow);
            ans %= mod;
        }
        printf("Case %lld: ", cas++);
        if(f) cout << ans << endl;
        else cout << -1 << endl;
        prime_pow.clear();
    }
    return 0;
}
