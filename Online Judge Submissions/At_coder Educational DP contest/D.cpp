#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, wei, v[105], w[105], dp[5][100005];
ll f()
{
    ll i, j;
    for(i = 0; i <= wei; i++){
        if(i < w[n-1]) dp[(n-1)%2][i] = 0;
        else dp[(n-1)%2][i] = v[n-1];
    }
    for(i = n-2; i >= 0; i--){
        for(j = 0; j <= wei; j++){
            ll a = 0, b = 0;
            if(j >= w[i])
                a = v[i] + dp[(i+1)%2][j-w[i]];
            b = dp[(i+1)%2][j];
            dp[i%2][j] = max(a,b);
        }
    }
    return dp[0][wei];
}
int main()
{
    ll i;
    cin >> n >> wei;
    for(i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << f() << endl;
    return 0;
}
