#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[30][155], n, x, power[26];

void str_pow()
{
    power[0] = 1;
    for(ll i = 1; i <= 25; i++)
        power[i] = 6*power[i-1];
}

ll f(ll in, ll rem)
{
    if(rem <= 0) return power[n-in];
    if(in == n) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];

    ll sum = 0;
    for(ll i = 1; i <= 6; i++){
        sum += f(in+1, rem-i);
    }

    return dp[in][rem] = sum;
}

int main()
{
    str_pow();

    ll t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> x;
        memset(dp, -1, sizeof dp);
        ll up = f(0, x);
        //cout << up << endl;
        ll down = power[n];
        ll g = __gcd(up, down);
        up /= g;
        down /= g;
        printf("Case %lld: ", cas++);
        if(up == 0 || down == 1)
            printf("%lld\n", up);
        else
            printf("%lld/%lld\n", up, down);
    }
    return 0;
}
