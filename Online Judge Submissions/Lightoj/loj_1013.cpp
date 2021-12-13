#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s, s2;
ll dp[55][55], dp2[55][55][55], tot;
ll f(ll i, ll j)
{
    if(i == s.size() or j == s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll a, b, c;
    a = b = c = -inf;
    if(s[i] == s2[j]){
        a = 1+f(i+1,j+1);
    }
    else{
        b = f(i+1,j);
        c = f(i,j+1);
    }
    return dp[i][j] = max(a,max(b,c));
}
ll g(ll i, ll j, ll num)
{
    if(i == s.size()){
        if(num+(s2.size()-j) == tot) return 1;
        return 0;
    }
    if(j == s2.size()){
        if(num+(s.size()-i) == tot) return 1;
        return 0;
    }
    if(dp2[i][j][num] != -1) return dp2[i][j][num];
    ll a = 0, b = 0;
    if(s[i] == s2[j])
        a = g(i+1,j+1,num+1);
    else{
        a = g(i+1,j,num+1);
        b = g(i,j+1,num+1);
    }
    return dp2[i][j][num] = a+b;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s >> s2;
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        tot = s.size()+s2.size()-f(0,0);
        printf("Case %lld: %lld %lld\n", cas++, tot, g(0,0,0));

    }
    return 0;
}
