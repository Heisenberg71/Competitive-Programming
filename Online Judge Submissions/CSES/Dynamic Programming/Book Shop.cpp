#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

int h[1003], s[1003];
int dp[1003][100005]; /// dp[i'th book][total price till now] = max pages

int main()
{
    int n, x;

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if(h[i] <= j) dp[i][j] = max(dp[i][j], s[i] + dp[i - 1][ j - h[i] ]);
            //cout << dp[i][j] << " ";
        }
        //cout << nl;
    }

    cout << dp[n][x] << nl;

    return 0;
}
