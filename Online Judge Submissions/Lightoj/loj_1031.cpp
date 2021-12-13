#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, arr[105], dp[105][105];
ll eval(ll x, ll y)
{
    if(x > y) return 0;
    return dp[x][y];
}
ll f()
{
    ll i, j, k;
    for(i = 1; i <= n; i++){
        for(j = 1; j < n-i+1; j++){
            ll mx = -inf;
            for(k = j; k <= j+i; k++){
                //cout << j << " " << j+i << " " << k << endl;
                mx = max(mx,(arr[k]-arr[j-1]) - eval(k+1,j+i));
                mx = max(mx,(arr[j+i]-arr[k-1]) - eval(j,k-1));
            }
            dp[j][j+i] = mx;
        }
    }
    return dp[1][n];
}
int main()
{
    ll t, cas = 1, i;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(i = 1; i <= n; i++){
            scanf("%lld", &arr[i]);
            dp[i][i] = arr[i];
            arr[i] += arr[i-1];
        }
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}

