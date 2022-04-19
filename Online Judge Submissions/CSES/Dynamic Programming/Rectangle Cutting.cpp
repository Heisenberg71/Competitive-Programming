#include <bits/stdc++.h>
#define ll long long
#define inf 1000000009
#define nl "\n"
using namespace std;

int dp[505][505];

int fun(int w, int h)
{
    if(w == h) return 0;
    if(dp[w][h] != -1) return dp[w][h];

    int ans = inf;
    for(int i = 1; i < w; i++)
        ans = min(ans, 1 + fun(i, h) + fun(w - i, h));
    for(int i = 1; i < h; i++)
        ans = min(ans, 1 + fun(w, i) + fun(w, h - i));

    return dp[w][h] = ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof dp);
    cout << fun(a, b) << nl;

    return 0;
}
