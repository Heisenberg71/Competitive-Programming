#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s1, s2, s3;
ll dp[55][55][55];
ll f(ll x, ll y, ll z)
{
    if(x == s1.size() or y == s2.size() or z == s3.size()) return 0;
    if(dp[x][y][z] != -1) return dp[x][y][z];
    ll a, b, c, d = -inf;
    if(s1[x] == s2[y] and s2[y] == s3[z])
        d = 1+f(x+1,y+1,z+1);
    a = f(x+1,y,z);
    b = f(x,y+1,z);
    c = f(x,y,z+1);
    return dp[x][y][z] = max(a,max(b,max(c,d)));
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s1 >> s2 >> s3;
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,0,0));
    }
    return 0;
}
