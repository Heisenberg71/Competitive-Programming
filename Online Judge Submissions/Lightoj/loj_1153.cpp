#include <bits/stdc++.h>
#define ll long long
#define inf (1 << 29)
using namespace std;

int n, src, sink, mat[105][105], reached[105], par[105], vis[105];
queue <int> q;

int bfs()
{
    memset(vis, 0, sizeof vis);
    memset(par, 0, sizeof par);
    memset(reached,  0, sizeof reached);
    q.push(src);
    vis[src] = 1;
    par[src] = 0;
    reached[src] = inf;
    while(!q.empty()){
        int u = q.front(); q.pop();
        //cout << u << endl;
        for(int v = 1; v <= n; v++){
            if(mat[u][v] && !vis[v]){
                int mn = min(mat[u][v], reached[u]);
                reached[v] = mn;
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    //cout << vis[sink] << endl;
    if(!vis[sink]) return 0;
    int u = par[sink], v = sink;
    while(u){
        mat[u][v] -= reached[sink];
        mat[v][u] += reached[sink];
        u = par[u];
        v = par[v];
    }

    return reached[sink];
}

int flow()
{
    int ans = 0;
    while(1){
        ll val = bfs();
        ans += val;
        if(!val) return ans;
    }
}

int main()
{
    int t, cas = 1, con, x, y, c;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> src >> sink >> con;
        while(con--){
            cin >> x >> y >> c;
            mat[x][y] += c;
            mat[y][x] += c;
        }
        printf("Case %d: %d\n", cas++, flow());
        memset(mat, 0, sizeof mat);
    }
    return 0;
}
