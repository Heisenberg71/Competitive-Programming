#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s, t;
ll dp[3005][3005], grid[3005][3005];
ll f(ll i, ll j)
{
    if(i == s.size() or j == t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll a = -inf, b = -inf, c = -inf;
    if(s[i] == t[j]) a = 1+f(i+1,j+1);
    else{
        b = f(i,j+1);
        c = f(i+1,j);
    }
    if(a >= b and a >= c) grid[i][j] = 1;
    else if(b >= a and b >= c) grid[i][j] = 2;
    else grid[i][j] = 3;

    return dp[i][j] = max(a,max(b,c));
}
void g(ll i, ll j)
{
    if(i == s.size() or j == t.size()) return;
    if(grid[i][j] == 1) cout << s[i], g(i+1,j+1);
    else if(grid[i][j] == 2) g(i,j+1);
    else g(i+1,j);
}
int main()
{
    ll i;
    cin >> s >> t;
    memset(dp,-1,sizeof(dp));
    f(0,0);
    g(0,0);
    cout << endl;
    return 0;
}
