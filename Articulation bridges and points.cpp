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
int n, m, tim, dis[LIM], low[LIM], par[LIM];
vector <int> edg[LIM], artpoint;

void dfs(int u)
{
    dis[u] = low[u] = tim++;
    int child = 0, mx = -inf;
    for(int i = 0; i < edg[u].size(); i++){
        int v = edg[u][i];
        if(v != par[u]){
            if(dis[v]){     /// BACK EDGE
                low[u] = min(low[u], dis[v]); /// IF TREE EDGE, LOW[U] = MIN(LOW[U] OF ALL OF ITS CHILD)
            }
            else{           /// TREE EDGE
                par[v] = u; /// SAVING PARENT
                dfs(v);
                low[u] = min(low[u], low[v]);   /// IF BACK EDGE, LOW[U] = MIN(MIN OF DIS[CHILD] AND LOW[U])
                if(low[v] >= dis[u] && u != 1)
                    mx = max(mx, dis[v]);
                child++;
            }
        }
    }
    if(u != 1 && mx >= dis[u]) artpoint.pb(u);  /// IF THE NODE IS NOT ROOT
    if(u == 1 && child > 1) artpoint.pb(u);     /// IF THE NODE IS ROOT CHECK IF (#CHILD > 1)
}

