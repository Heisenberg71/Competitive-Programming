#include <bits/stdc++.h>
#define ll long long
using namespace std;
double coin[3005], dp[3005][3005];
ll n;
double f()
{
    ll i, j;
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            dp[i][j] = 0.0;
    dp[0][0] = 1;
    for(i = 1; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(!j) dp[i][j] = (1.0-coin[i])*dp[i-1][j];
            else dp[i][j] = coin[i]*dp[i-1][j-1] + (1.0-coin[i])*dp[i-1][j];
        }
    }
    double ans = 0.0;
    for(i = 0; i <= n; i++){
        if(i > n-i) ans += dp[n][i];
    }
    return ans;
}
int main()
{
    ll i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> coin[i];
    printf("%0.10lf\n", f());
    return 0;
}
