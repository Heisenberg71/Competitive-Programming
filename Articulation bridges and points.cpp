/// ARTICULATION BRIDGES
#define ll long long  /// MACROS NEEDED
#define pb push_back  /// MACROS NEEDED
#define LIM 100005    /// MACROS NEEDED
ll dis[LIM], vis[LIM], par[LIM], low[LIM], cnt, n;
vector <ll> ver[LIM];
vector <pair<ll,ll> > ans;
void dfs(ll u)
{
    dis[u] = low[u] = cnt++;
    for(ll i = 0; i < ver[u].size(); i++){
        ll v = ver[u][i];
        if(v != par[u]){     
            if(vis[v] == 0){  /// TREE EDGES
                par[v] = u;   /// SAVING PARTENTS
                vis[v] = 1;   
                dfs(v);       
                low[u] = min(low[u], low[v]); /// IF TREE EDGE, LOW[U] = MIN(LOW[U] OF ALL OF ITS CHILD)
            }
            else if(vis[v] == 1){   /// BACK EDGES
                low[u] = min(low[u], dis[v]); /// IF BACK EDGE, LOW[U] = MIN(MIN OF DIS[CHILD] AND LOW[U])
            }
            if(dis[u] < low[v]) ans.pb({min(u,v), max(u,v)});  /// ARTICULATION EDGES
        }
    }
    vis[u] = 2;   /// FORWARD EDGES
}

/// ARTICULATION POINTS
#define ll long long  /// MACROS NEEDED
#define LIM 100005    /// MACROS NEEDED
ll dis[LIM], vis[LIM], par[LIM], low[LIM], cnt, n;
vector <ll> ver[LIM];
vector <ll> ans;
void dfs(ll u)
{
    dis[u] = low[u] = cnt++;
    for(ll i = 0; i < ver[u].size(); i++){
        ll v = ver[u][i];
        if(v != par[u]){     
            if(vis[v] == 0){  /// TREE EDGES
                par[v] = u;   /// SAVING PARTENTS
                vis[v] = 1;   
                dfs(v);       
                low[u] = min(low[u], low[v]); /// IF TREE EDGE, LOW[U] = MIN(LOW[U] OF ALL OF ITS CHILD)
            }
            else if(vis[v] == 1){   /// BACK EDGES
                low[u] = min(low[u], dis[v]); /// IF BACK EDGE, LOW[U] = MIN(MIN OF DIS[CHILD] AND LOW[U])
            }
            if(dis[u] <= low[v]) ans.pb(u);  /// ARTICULATION POINTS
        }
    }
    vis[u] = 2;   /// FORWARD EDGES
}
