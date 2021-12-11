#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[45][5], dp2[45][5];
string s, s2, s3;

ll f2(ll pos, ll issmall)
{
    /// HOW MANY NUMBERS SMALLER THAN n IS POSSIBLE FROM THIS STATE (pos,issmall)
    if(pos == s.size()) return 1;
    if(dp2[pos][issmall] != -1) return dp2[pos][issmall];
    ll lo = 0, hi = s[pos]-'0', sum = 0;
    if(issmall) hi = 1;
    for(; lo <= hi; lo++){
        sum += f2(pos+1,issmall | (lo<hi));
    }
    return dp2[pos][issmall] = sum;
}

ll f(ll pos, ll issmall)
{
    if(pos == s.size()) return 0;
    if(dp[pos][issmall] != -1) return dp[pos][issmall];
    ll lo = 0, hi = s[pos]-'0', sum = 0;
    if(issmall) hi = 1;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi));
        /// ALREADY STARTED AND RIGHT-NOW WE ARE PUTTING 0 AT CURRENT POSSITION
        /// SO WE WILL HAVE TO FIND OUT IN HOW MANY WAYS THIS ZERO WILL CONTRIBUTE
        if(lo == 1) tem += f2(pos+1,issmall | (lo<hi));
        sum += tem;
    }
    return dp[pos][issmall] = sum;
}

int main()
{
    ll a, b, t, cas = 1;

    while(cin >> a >> b){
        if(!a && !b) break;

        a--;
        while(a){
            s += ('0' + a%2);
            a /= 2;
        }

        while(b){
            s2 += ('0' + b%2);
            b /= 2;
        }

        reverse(s.begin(), s.end());
        reverse(s2.begin(), s2.end());

        ll tem = s2.size() - s.size();
        while(tem--)
            s3 += '0';
        s3 += s; /// s3 < s2

        s = s2; //cout << s << endl;
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        ll ans = f(0, 0); //cout << ans << endl;
        s = s3; //cout << s << endl;
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        ans -= f(0, 0);
        printf("Case %lld: %lld\n", cas++, ans);

        s.clear(), s2.clear(), s3.clear();
    }


    return 0;
}
