#include <bits/stdc++.h>
#define ll long long
#define inf 10000000000000000
using namespace std;
ll arr[105], le[105], ri[105], dp[105][105];
ll cal(ll m, ll k, ll j)
{
    ll a, b;
    a = (le[m]-le[k-1])%100;
    b = (ri[m+1]-ri[j+1])%100;
    return a*b;
}
ll val(ll x, ll y)
{
    if(x == y) return 0;
    return dp[x][y];
}
ll f(ll l, ll r)
{
    ll i, j, k, m, ans;
    for(i = l; i <= r; i++){
        for(j = i, k = 1; j <= r; j++, k++){
            ans = inf;
            for(m = k; m < j; m++){
                ll a, b;
                a = val(k,m);
                b = val(m+1,j);
                ll tem = a + b + cal(m, k, j);
                ans = min(ans,tem);
            }
            dp[k][j] = ans;
        }
    }
    return dp[1][r];
}
int main()
{
    ll n, i;
    while(cin >> n){
        for(i = 1; i <= n; i++)
            cin >> arr[i];

        le[0] = 0;
        for(i = 1; i <= n; i++)
            le[i] = (le[i-1]+arr[i]);

        ri[n+1] = 0;
        for(i = n; i > 0; i--)
            ri[i] = (ri[i+1]+arr[i]);

        if(n == 1) cout << 0 << endl;
        else cout << f(1,n) << endl;
    }
    return 0;
}
