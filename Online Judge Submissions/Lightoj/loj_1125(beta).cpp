#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, d, arr[205], dp[205][15][25];

//ll f(ll in, ll cnt, ll rem)
//{
//    if(in == n){
//        if(cnt == m and rem == 0) return 1;
//        return 0;
//    }
//    if(cnt > m) return 0;
//
//    if(dp[in][cnt][rem] != -1) return dp[in][cnt][rem];
//
//    ll a, b;
//    a = f(in+1, cnt+1, ((rem+arr[in])%d + d)% d);
//    b = f(in+1, cnt, rem);
//
//    return dp[in][cnt][rem] = a + b;
//}

ll f()
{
    ll i, j, k;

    dp[n][m][0] = 1;

    for(i = n-1; i >= 0; i--){
        for(j = 0; j <= m; j++){
            for(k = 0; k < d; k++){
                dp[i][j][k] = dp[i+1][j+1][(((k + arr[i]) % d) + d) %d] +
                              dp[i+1][j][k];
            }
        }
    }

    return dp[0][0][0];
}

int main()
{
    ll t, cas = 1, i, q;
    cin >> t;
    while(t--){
        cin >> n >> q;
        for(i = 0; i < n; i++)
            cin >> arr[i];

        printf("Case %lld:\n", cas++);

        while(q--){
            cin >> d >> m;
            cout << f() << endl;
        }
    }
    return 0;
}
