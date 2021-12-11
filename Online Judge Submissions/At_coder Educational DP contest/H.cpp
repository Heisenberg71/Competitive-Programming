#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
char grid[1005][1005];
ll dp[1005][1005], n, m;
ll eval(ll x, ll y)
{
    if(x < 0 or y < 0) return 0;
    return dp[x][y];
}
ll f()
{
    ll i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                if(i == 0 and j == 0) dp[i][j] = 1;
                else dp[i][j] = (eval(i-1,j) + eval(i,j-1))%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int main()
{
    ll i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << f() << endl;
    return 0;
}
