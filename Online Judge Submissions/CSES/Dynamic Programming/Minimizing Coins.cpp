#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define nl "\n"
using namespace std;

int c[LIM], dp[LIM], coins[LIM];

int main()
{
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> c[i];

    dp[x] = 1;
    for(int i = x - 1; i >= 0; i--){
        coins[i] = LIM;
        for(int j = 0; j < n; j++){
            if(i + c[j] <= x && dp[ i + c[j] ]){
                dp[i] = 1;
                coins[i] = min(coins[i], 1 + coins[ i + c[j] ]);
            }
        }
    }

    if(dp[0]) cout << coins[0] << nl;
    else cout << -1 << nl;

    return 0;
}
