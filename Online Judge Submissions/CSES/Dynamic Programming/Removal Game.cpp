#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

ll arr[5005], dp[5005][5005];

ll f(int L, int R)
{
    if(L > R) return 0;
    if(dp[L][R] != -1) return dp[L][R];

    ll a = arr[L] - f(L + 1, R);
    ll b = arr[R] - f(L, R - 1);

    return dp[L][R] = max(a, b);
}

int main()
{
    int n;

    cin >> n;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    memset(dp, -1, sizeof dp);
    ll sub = f(0, n - 1);

    cout << (sum + sub)/2 << nl;

    return 0;
}

/// a + b = x
/// a - b = y
