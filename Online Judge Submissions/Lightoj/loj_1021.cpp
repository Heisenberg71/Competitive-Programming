#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll base, k, dp[(1<<17)][20];
string s;
ll digit(char ch)
{
    if(ch >= 'A') return ch-'A'+10;
    return ch-'0';
}
ll f()
{
    ll i, j, m, n = s.size();
    dp[0][0] = 1;
    for(i = 0; i < (1<<n); i++){
        for(j = 0; j < k; j++){
            for(m = 0; m < n; m++){
                if(!(i&(1<<m))){
                    ll dig = digit(s[m]);
                    dp[i|(1<<m)][(j*base+dig)%k] += dp[i][j];
                }
            }
        }
    }
    return dp[(1<<n)-1][0];
}
int main()
{
    ll t, cas = 1;
    cin >> t;
    while(t--){
        cin >> base >> k >> s;
        memset(dp,0,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
