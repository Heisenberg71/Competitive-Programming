#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ncr(ll n, ll r)
{
    ll cnt = 0, ans = 1;
    if(n < 4) return 0;
    while(cnt < 4){
        ans *= n;
        n--;
        cnt++;
    }
    return ans/24;
}
int main()
{
    ll t, n, i, cnt[10005], j, res[10005], cas = 1, x;
    cin >> t;
    while(t--){
        cin >> n;
        memset(cnt,0,sizeof cnt);
        memset(res,0,sizeof res);
        for(i = 0; i < n; i++){
            cin >> x;
            cnt[x]++;
        }
        for(i = 0; i <= 10000; i++){
            res[i] = ncr(cnt[i],4);
        }
        ll ans = 0;
        for(i = 10000; i > 1; i--){
            ll tot = 0, tot2 = 0;
            for(j = i; j <= 10000; j += i){
                tot += cnt[j];
                if(i != j) tot2 += res[j];
            }
            res[i] = ncr(tot,4)-tot2;
            ans += res[i];
        }
        printf("Case %lld: %lld\n", cas++, ncr(n,4)-ans);
    }
    return 0;
}
