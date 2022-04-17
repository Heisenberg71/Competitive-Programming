#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define nl "\n"
using namespace std;

int dp[LIM];

int main()
{
    int n;

    cin >> n;

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        dp[i] = LIM;
        while(temp){
            dp[i] = min(dp[i], 1 + dp[i - temp%10]);
            temp /= 10;
        }
    }

    cout << dp[n] << nl;

    return 0;
}
