#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 10000000005
#define mod 100000007
using namespace std;
//vector <ll> v, v2;
//ll fac[2000005], v[102719+5], v2[102720+5], sz;
ll fac[2000005], v[200005], v2[200005], sz;
ll overflow(ll n, ll p)
{
    ll res = n*p;
    if(res == 0) return 1;
    if(res/n == p) return 0;
    return 1;
}
ll power(ll a, ll b)
{
    if(!b) return 1;
    ll x = power(a,b/2);
    if(overflow(x,x)) x = 0;
    x = (x*x);
    if(b%2){
        if(overflow(x,a)) x = 0;
        x = (x*a);
    }
    return x;
}
void make()
{
    ll i, j, k;
    for(i = 2, k = 0; i < 100005; i++){ //cout << "i " << i << endl;
        for(j = 2; j < 35; j++){

            ll x = power(i,j);
        //cout << "j " << j << endl;
            //ll pre = s.size();
            //s.insert(x);
            if(x and x <= LIM) v2[k] = x, k++;
        }
    }
    v2[k] = LIM;
    sort(v2,v2+k+1); //cout << k << endl;
    for(i = 0, j = 0; i < k; i++){
        if(v2[i] != v2[i+1]) v[j] = v2[i], j++;
    }
//    sort(v,v+j);
    sz = j;
//    for(ll i = 0; i < 100; i++)
//        cout << v[i] << " ";
//    cout << endl;
//cout << v.size() << endl;
}
ll lb(ll n)
{
    ll lo = 0, hi = sz, md;
    while(lo<hi){
        md = (lo+hi)/2;
        if(n <= v[md]) hi = md;
        else lo = md+1;
    }
    return lo;
}
ll ub(ll n)
{
    ll lo = 0, hi = sz, md;
    while(lo<hi){
        md = (lo+hi)/2;
        if(n < v[md]) hi = md;
        else lo = md+1;
    }
    return lo;
}
void fact()
{
    ll i;
    fac[0] = 1;
    for(i = 1; i < 2000005; i++)
        fac[i] = (i*fac[i-1])%mod;
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
    make();
    fact();
    ll t, a, b, cas = 1, n;
//    cout << v.size() << " " << v2.size() << endl;
//    cout << sz << endl;
    cin >> t;
    while(t--){
        cin >> a >> b;
        n = ub(b)-lb(a); //cout << n << endl;
        ll up = ((fac[2*n])%mod+mod)%mod;
        ll down = ((fac[n]*fac[n])%mod+mod)%mod;
        ll down2 = ((fac[n+1]*fac[n-1])%mod+mod)%mod;
        ll ans = ((up*bigmod(down,mod-2) - up*bigmod(down2,mod-2))%mod + mod ) %mod;
        if(!n) ans = 0;
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
