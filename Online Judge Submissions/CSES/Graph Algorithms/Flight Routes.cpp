#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 100005
#define nl '\n'
using namespace std;

bool found;
vector <int> edge[LIM], ans;
int vis[LIM];
stack <int> stk;

void dfs(int u)
{
    if(found || vis[u] == 2) return;
    if(vis[u] == 1){
        found = 1;
        ans.pb(u);
        while(stk.top() != u){
            ans.pb(stk.top());
            stk.pop();
        }
        ans.pb(u);
        return;
    }
    stk.push(u);
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        dfs(v);
    }
    stk.pop();
    vis[u] = 2;
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
    }

    for(int i = 1; i <= n; i++){
        if(!found && !vis[i]) dfs(i);
    }

    if(found){
        cout << ans.size() << nl;
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << nl;
    }
    else cout << "IMPOSSIBLE" << nl;

    return 0;
}
