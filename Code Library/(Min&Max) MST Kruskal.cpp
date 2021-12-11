#define ll long long  /// MACRO NEEDED
#define pb push_back  /// MACRO NEEDED

int n, pr[105], sz[105];
struct abc{
    int w, u, v;
};
vector <abc> edg;

bool cmp(abc x, abc y)
{
    return x.w < y.w;
}

int findP(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);
    if(u != v){
        if(sz[u] < sz[v]){  /// MARGING SMALLER COMPONENT WITH LARGER COMPONENT
            pr[u] = v;
            sz[v] += sz[u];
        }
        else{
            pr[v] = u;
            sz[u] += sz[v];
        }
    }
}

int kruskal(int state)  /// STATE = 0 (MIN), STATE = 1(MAX)
{
    int i;
    for(i = 0; i <= n; i++){
        pr[i] = i;
        sz[i] = 1;
    }
    sort(edg.begin(), edg.end(), cmp);
    if(state)
        reverse(edg.begin(), edg.end());
    int cost = 0;
    for(i = 0; i < edg.size(); i++){
        int parx = findP(edg[i].u);
        int pary = findP(edg[i].v);
        if(parx != pary){
            cost += edg[i].w;
            connect(parx, pary);
        }
    }
    return cost;
}
