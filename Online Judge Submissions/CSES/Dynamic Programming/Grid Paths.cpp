#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define nl "\n"
#define mod 1000000007
using namespace std;

int dp[1003][1003];
string grid[1003];

int main()
{
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') continue;

            if(i == 0 && j == 0) dp[0][0] = 1;
            else if(i == 0) dp[i][j] = dp[i][j - 1];
            else if(j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%mod;
        }
    }

    cout << dp[n - 1][n - 1] << nl;

    return 0;
}
