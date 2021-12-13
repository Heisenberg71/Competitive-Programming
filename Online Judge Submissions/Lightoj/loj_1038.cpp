#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> v[100005];
double dp[100005];
void make_prime()
{
    ll i, j, sq = sqrt(100005);
    for(i = 1; i <= 100000; i++){
        for(j = i; j <= 100000; j += i)
            v[j].pb(i);
    }
}
void f()
{
    ll i, j;
    dp[1] = 0;
    for(i = 2; i <= 100000; i++){
        double sum = 0.0;
        for(j = 0; j < v[i].size(); j++){
            sum += dp[v[i][j]];
        }
        double sz = v[i].size();
        dp[i] = (sum+sz)/(sz-1);
    }
}
int main()
{
    make_prime();
    f();
    ll t, i, cas = 1, n;
    cin >> t;
    while(t--){
        cin >> n;
        printf("Case %lld: %0.10lf\n", cas++, dp[n]);
    }
    return 0;
}
