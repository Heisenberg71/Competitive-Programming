#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll dp[105][105];
ll f()
{
    ll i, j;

    for(i = 0; i < s.size(); i++)
        dp[i][i] = 1;

    for(i = 1; i < s.size(); i++){
        for(j = 0; j < s.size()-i; j++){
            if(s[j] == s[j+i]) dp[j][j+i] = 1 + dp[j+1][j+i] + dp[j][j+i-1];
            else dp[j][j+i] = dp[j+1][j+i] + dp[j][j+i-1] - dp[j+1][j+i-1];
        }
    }

    return dp[0][s.size()-1];
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s;
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
