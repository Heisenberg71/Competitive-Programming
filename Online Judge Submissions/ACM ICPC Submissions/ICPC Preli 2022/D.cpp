#include <bits/stdc++.h>
#define LIM 1000006
#define ll long long
#define pb push_back
using namespace std;

ll ans;

ll basePower[2][LIM];
ll mod[2] = {1000000007, 1000000009};
ll base[2] = {31, 101};

string str;
char temp[LIM];

ll vis[LIM];
vector <ll> edge[LIM];

void preCal()
{
    basePower[0][0] = basePower[1][0] = 1;
   for(ll j = 0; j < 2; j++){
        for(ll i = 1; i < 1000006; i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
        }
    }
}

void dfs(ll u, ll depth, ll forwardHash, ll backwardHash, ll forwardHash2, ll backwardHash2)
{
    forwardHash = (forwardHash + (basePower[0][depth]*(str[u] - 'A' + 1)) %mod[0]) %mod[0];
    backwardHash = ((backwardHash*base[0]) %mod[0] + (str[u] - 'A' + 1)) %mod[0];

    forwardHash2 = (forwardHash2 + (basePower[1][depth]*(str[u] - 'A' + 1)) %mod[1]) %mod[1];
    backwardHash2 = ((backwardHash2*base[1]) %mod[1] + (str[u] - 'A' + 1)) %mod[1];

    if(forwardHash == backwardHash && forwardHash2 == backwardHash2) ans++;

//    cout << forwardHash << " " << backwardHash << " " << forwardHash2 << " " << backwardHash2 << endl;

    vis[u] = 1;

    for(ll i = 0; i < edge[u].size(); i++){
        ll v = edge[u][i];
        if(!vis[v]) dfs(v, depth + 1, forwardHash, backwardHash, forwardHash2, backwardHash2);
    }
}

int main()
{
    ll t, n, cas = 1;
    char ch[LIM];
    preCal();

    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        scanf("%s", ch);
        str = ch;
        str = '*' + str;
        for(ll i = 0; i < n - 1; i++){
            ll u, v;
            scanf("%lld %lld", &u, &v);
            edge[u].pb(v);
            edge[v].pb(u);
        }

        ans = 0;
        dfs(1, 0, 0, 0, 0, 0);

        for(ll i = 0; i <= n; i++){
            vis[i] = 0;
            edge[i].clear();
        }

        ll g = __gcd(ans, n);
        ans /= g;
        n /= g;

        printf("Case %lld: %lld/%lld\n", cas++, ans, n);
    }
    return 0;
}
