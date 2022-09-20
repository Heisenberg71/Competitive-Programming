#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define nl '\n'
#define LIM 100005
using namespace std;

int n, m, vis[LIM];
vector <int> edge[LIM], ans;
stack <int> stk;

void dfs(int u, int tim, int par)
{
    if(ans.size()) return;

    ///cout << u << " ";

    stk.push(u);
    if(vis[u]){
        if(tim - vis[u] > 2){
            ans.pb(stk.top()), stk.pop();
            while(stk.top() != u){
                ans.pb(stk.top());
                stk.pop();
            }
            ans.pb(stk.top());
            for(int i = 0; i < ans.size(); i++)
                stk.push(ans[i]);
        }
        return;
    }
    vis[u] = tim;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != par) dfs(v, tim + 1, u);
    }

    stk.pop();
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i] && ans.size() == 0) dfs(i, 1, -1);
        while(!stk.empty()) stk.pop();
    }

    if(ans.size() == 0){
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }

    cout << ans.size() << nl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << nl;

    return 0;
}
