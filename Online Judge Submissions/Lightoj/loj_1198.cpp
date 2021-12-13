#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, me[55], op[55], dp[55][55];

ll f(ll i, ll j)
{
    if(i == n+1 || j == n+1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int point = 0;
    if(me[i] > op[j]) point = 2;
    if(me[i] == op[j]) point = 1;

    return dp[i][j] = max(point + f(i + 1, j + 1), max(f(i + 1, j), f(i, j + 1)));
}

int main()
{
    int t, cas = 1;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &me[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &op[i]);

        sort(me + 1, me + n + 1);
        sort(op + 1, op + n + 1);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cas++, f(1, 1));
    }

    return 0;
}
