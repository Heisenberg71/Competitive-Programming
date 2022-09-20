#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define LIM 100005
using namespace std;

int vis[LIM];
vector <int> edge[LIM], inv[LIM], ans;
stack <int> stk;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs2(int u)
{
    vis[u] = 1;
    for(int i = 0; i < inv[u].size(); i++){
        int v = inv[u][i];
        if(!vis[v]) dfs2(v);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        inv[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

//    while(!stk.empty()){
//        cout << stk.top() << nl;
//        stk.pop();
//    }

    memset(vis, 0, sizeof vis);
    while(!stk.empty()){
        if(!vis[stk.top()]){
            dfs2(stk.top());
            ans.pb(stk.top());
        }
        stk.pop();
    }

    if(ans.size() <= 1) cout << "YES" << nl;
    else{
        cout << "NO" << nl;
        cout << ans[1] << " " << ans[0] << nl;
    }

    return 0;
}
