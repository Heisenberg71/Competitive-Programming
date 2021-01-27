vector <int> v[1005], seq;
int vis[1005];
void dfs(int u)
{
    vis[u] = 1;
    seq.pb(u);
    for(int i = 0; i < v[u].size(); i++){
        if(!vis[v[u][i]]) dfs(v[u][i]);
    }
}
