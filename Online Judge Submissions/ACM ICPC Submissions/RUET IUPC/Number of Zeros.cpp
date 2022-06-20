#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define mod 1000000007
using namespace std;

ll fac[LIM], facInv[LIM];

ll Tzeros(int n, int base) /// O(log(n))
{
    ll res = 0;
    while(n){
        res += n/base;
        n /= base;
    }
    return res;
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

void makeFact() /// O(nlogn)
{
    fac[0] = 1, facInv[0] = 1;
    for(int i = 1; i < LIM; i++){
        fac[i] = (i*fac[i - 1]) %mod;
        facInv[i] = bigmod(fac[i], mod - 2);
    }
}

ll ncr(int n, int r) /// O(1)
{
    ll up = fac[n];
    ll down = (facInv[r]*facInv[n - r]) %mod;
    return (up*down) %mod;
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
