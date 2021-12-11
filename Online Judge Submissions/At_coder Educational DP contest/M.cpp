#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll n, k, arr[105], dp[2][100005];
ll f()
{
    ll i, j;

    for(i = 0; i <= arr[0]; i++){
        dp[0][i] = 1;
    }
    for(i = 1; i <= k; i++){
        dp[0][i] += dp[0][i-1];
        dp[0][i] %= mod;
    }
    for(i = 1; i < n; i++){
        for(j = 0; j <= k; j++){
            if(j-arr[i]-1 >= 0) dp[i%2][j] = (dp[(i-1)%2][j]-dp[(i-1)%2][j-arr[i]-1]+mod)%mod;
            else dp[i%2][j] = dp[(i-1)%2][j];
        }
        for(j = 1; j <= k; j++){
            dp[i%2][j] += dp[i%2][j-1];
            dp[i%2][j] %= mod;
        }
    }

//    for(i = 0; i < n; i++){
//        for(j = 0; j <= k; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//    }
//    cout << n << " " << k << endl;
    return (dp[(n-1)%2][k]-dp[(n-1)%2][k-1]+mod)%mod;

}
int main()
{
    ll i, sum = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum < k) cout << 0 << endl;
    else cout << f() << endl;
    return 0;
}
