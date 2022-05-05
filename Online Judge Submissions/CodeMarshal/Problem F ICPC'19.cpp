#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define MAXX 100005
#define mod 132021913
using namespace std;
ll cnt[MAXX], csum[MAXX];
ll bigmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = bigmod(a, b/2);
    x = (x*x)%mod;
    if(b%2 == 1) x = (x*a)%mod;
    return x;
}
int main()
{
    ll n, arr[LIM], i, j, cas = 1, curr_gcd, t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(cnt,0,sizeof cnt);
        memset(csum,0,sizeof csum);
        for(i = 0; i < n; i++){
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        for(curr_gcd = 1; curr_gcd < MAXX; curr_gcd++){
            ll tot = 0;
            for(i = curr_gcd; i < MAXX; i += curr_gcd){
                csum[curr_gcd] += (tot*(cnt[i]*i)%mod)%mod;
                csum[curr_gcd] %= mod;
                csum[curr_gcd] += (i*(i*((cnt[i]*(cnt[i]-1))/2)%mod)%mod)%mod;
                csum[curr_gcd] %= mod;
                tot += (cnt[i]*i)%mod;
                tot %= mod;
            }
        }
//        for(i = 0; i < 25; i++)
//            cout << csum[i] << " ";
//        cout << endl;
        ll ans = 0;
        for(i = MAXX-1; i > 0; i--){
            for(j = 2*i; j < MAXX; j += i){
                csum[i] -= csum[j];
                csum[i] %= mod;
            }
            csum[i] = (csum[i]+mod)%mod;
            ans += (((csum[i]*bigmod(i,mod-2))%mod) + mod)%mod;
            ans = ans%mod;
        }
//        for(i = 0; i < 25; i++)
//            cout << csum[i] << " ";
//        cout << endl;
        printf("Case %lld: %lld\n", cas++, ans);
        //if(n == 1) cout << arr[0] << endl;
        //cout << ans << endl;
    }
    return 0;
}
