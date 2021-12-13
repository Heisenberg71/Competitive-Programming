#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s1, s2, s3;
ll dp[55][55][55];
ll eval(ll x, ll y, ll z){
    if(x == s1.size() or y == s2.size() or z == s3.size())
        return 0;
    return dp[x][y][z];
}
ll f()
{
    ll i, j, k;
    for(i = s1.size()-1; i >= 0; i--){
        for(j = s2.size()-1; j >= 0; j--){
            for(k = s3.size()-1; k >= 0; k--){
                dp[i][j][k] = -inf;
                if(s1[i] == s2[j] and s2[j] == s3[k]) dp[i][j][k] = 1+eval(i+1,j+1,k+1);
                dp[i][j][k] = max(dp[i][j][k],max(eval(i+1,j,k),max(eval(i,j+1,k),eval(i,j,k+1))));
            }
        }
    }
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s1 >> s2 >> s3;
        f();
        printf("Case %lld: %lld\n", cas++, dp[0][0][0]);
    }
    return 0;
}
