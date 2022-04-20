#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define mod 1000000007
using namespace std;

int n, dp[505][250005];

int fun(int pos, int sum)
{
    if(sum == 0) return 1;
    if(pos == n || sum < 0) return 0;
    if(dp[pos][sum] != -1) return dp[pos][sum];

    int a = fun(pos + 1, sum - pos);
    int b = fun(pos + 1, sum);

    return dp[pos][sum] = (a + b)%mod;
}

int main()
{
    cin >> n;

    int sum = (n*(n + 1))/2;
    if(sum%2) cout << 0 << nl;
    else{
        memset(dp, -1, sizeof dp);
        cout << fun(1, sum/2) << nl;
    }

    return 0;
}
