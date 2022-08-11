#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int ans;
bool taken[LIM];
vector <int> edge[LIM];

void dfs(int u, int pr)
{
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr) dfs(v, u);
    }

    if(pr != -1 && !taken[pr] && !taken[u]){
        taken[pr] = taken[u] = 1;
        ans++;
    }
}

int main()
{
    int n;

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs(1, -1);
    cout << ans << nl;

    return 0;
}
