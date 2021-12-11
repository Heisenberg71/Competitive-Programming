#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[3005], dp[3005][3005];
ll f()
{
    ll i, j;

    for(i = 0; i < n; i++)
        dp[i][i] = arr[i];

    for(i = 1; i < n; i++)
        for(j = 0; j < n-i; j++)
            dp[j][j+i] = max(arr[j]-dp[j+1][j+i],arr[j+i]-dp[j][j+i-1]);

    return dp[0][n-1];
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << f() << endl;
    return 0;
}

