#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define mod 1000000007
using namespace std;

ll fac[LIM];

ll Tzeros(int n, int base) /// O(log(n))
{
    ll res = 0;
    while(n){
        res += n/base;
        n /= base;
    }
    return res;
}

void makeFact() /// O(n)
{
    fac[0] = 1;
    for(int i = 1; i < LIM; i++)
        fac[i] = (i*fac[i - 1]) %mod;
}

ll bigmod(ll a, ll b) /// O(log(b))
{
    a %= mod;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*a) %mod;
        a = (a*a) %mod;
        b >>= 1;
    }
    return res;
}

ll ncr(int n, int r) /// O(log(n))
{
    ll up = fac[n];
    ll down = (fac[r]*fac[n - r]) %mod;
    return (up*bigmod(down, mod - 2)) %mod;
}

int main()
{
    makeFact();

    int t, cas = 1, n, base;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &base);

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += (ncr(n - 1, i)*Tzeros(i + 1, base)) %mod;
            ans %= mod;
        }

        printf("Case %d: %lld\n", cas++, ans);
    }

    return 0;
}
