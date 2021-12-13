#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, d, arr[205], dp[205][15][25];

ll f(ll in, ll cnt, ll rem)
{
    if(in == n){
        if(cnt == m and rem == 0) return 1;
        return 0;
    }
    if(cnt > m) return 0;

    if(dp[in][cnt][rem] != -1) return dp[in][cnt][rem];

    ll a, b;
    a = f(in+1, cnt+1, ((rem+arr[in])%d + d)% d);
    b = f(in+1, cnt, rem);

    return dp[in][cnt][rem] = a + b;
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
            memset(dp, -1, sizeof dp);
            cout << f(0, 0, 0) << endl;
        }
    }
    return 0;
}
