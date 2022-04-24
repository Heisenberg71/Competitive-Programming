#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define mod 1000000007
#define nl "\n"
using namespace std;

ll dp[LIM][2];

void precal()
{
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < LIM; i++){
        dp[i][0] += 2*dp[i - 1][0];
        dp[i][0] += dp[i - 1][1];

        dp[i][1] += dp[i - 1][0];
        dp[i][1] += 4*dp[i - 1][1];

        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
}

int main()
{
    precal();

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1])%mod << nl;
    }

    return 0;
}
