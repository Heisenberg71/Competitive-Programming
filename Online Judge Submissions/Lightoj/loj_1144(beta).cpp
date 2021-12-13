#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, arr[15], dp[15][15];
ll f()
{
    ll i, j, m;

    for(i = 0; i < n; i++)
        dp[k][i] = 1;

    for(i = k-1; i >= 0; i--){
        for(j = n-1; j >= 0; j--){
            ll sum = 0;
            if(i == 0 and j == 0){
                for(m = 0; m < n; m++)
                    sum += dp[i+1][m];
            }
            else{
                for(m = j; m < n and arr[j]+2 >= arr[m]; m++)
                    sum += dp[i+1][m];
                for(m = j-1; m >= 0 and arr[m]+2 >= arr[j]; m--)
                    sum += dp[i+1][m];
            }
            dp[i][j] = sum;
        }
    }

    return dp[0][0];
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
