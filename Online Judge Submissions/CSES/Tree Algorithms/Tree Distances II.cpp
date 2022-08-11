#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

ll n, dp[LIM], subTree[LIM], ans[LIM];
vector <int> edge[LIM];

void dfs(int u, int pr)
{
    subTree[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr){
            dfs(v, u);
            subTree[u] += subTree[v];
            dp[u] += dp[v] + subTree[v];
        }
    }
}

void rerootingDFS(int u, int pr)
{
//    cout << u << " " << dp[u] << nl;
    ans[u] = dp[u];
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr){
            ll prevU = dp[u];
            ll prevV = dp[v];

            dp[u] = dp[u] - dp[v] - subTree[v];
            dp[v] = dp[v] + dp[u] + (n - subTree[v]);

            rerootingDFS(v, u);

            dp[u] = prevU;
            dp[v] = prevV;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs(1, -1);

//    for(int i = 1; i <= n; i++)
//        cout << dp[i] << " ab " << subTree[i] << nl;

    rerootingDFS(1, -1);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;

//    for(int i = 1; i <= n; i++)
//        cout << dp[i] << " xy " << subTree[i] << nl;

    return 0;
}

/*

14
1 2
1 3
1 4
2 5
3 6
3 7
4 8
5 9
5 10
6 11
8 12
8 13
13 14

*/
