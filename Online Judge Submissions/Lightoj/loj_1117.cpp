#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, arr[20];
ll phi()
{
    ll lim = 1, i, ans = 0;
    while(m--)
        lim *= 2;
    for(i = 1; i < lim; i++){
        ll tem = i, mult = 1, cnt = 0, f = 1, coun = 0;
        while(tem){
            if(tem%2) mult = (mult/__gcd(mult,arr[cnt]))*arr[cnt], coun++;
            if(mult > n){f = 0; break;}
            tem /= 2;
            cnt++;
        }
        if(f){
            if(coun%2) ans += n/mult;
            else ans -= n/mult;
        }
    }
    return n-ans;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i = 0; i < m; i++)
            cin >> arr[i];
        printf("Case %lld: %lld\n", cas++, phi());
    }
    return 0;
}
