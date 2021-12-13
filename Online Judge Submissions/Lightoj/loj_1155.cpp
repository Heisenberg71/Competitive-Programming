#include <bits/stdc++.h>
#define ll long long
#define inf (1 << 29)
using namespace std;

int n, m, edg[205][205], vis[205], send[205], par[205];
int N;
queue <int> q;

int bfs()
{
    q.push(0);
    memset(vis, 0, sizeof vis);
    memset(send, 0, sizeof send);
    vis[0] = 1;
    par[0] = -1;
    send[0] = inf;
    while(!q.empty()){
        int u = q.front(); q.pop();
        //cout << "u: " << u << endl;
        for(int v = 0; v <= N; v++){
            if(!vis[v] && edg[u][v]){
                send[v] = min(send[u], edg[u][v]);
                par[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if(!vis[N]) return 0;
    int v = N, u = par[N];
    while(u){
        if(v != N){
            edg[u][v] -= send[N];
            edg[v][u] += send[N];
        }
        u = par[u];
        v = par[v];
    }

    return send[N];
}

int flow()
{
    int ans = 0;
    while(1){
        int cnt = bfs();
        if(cnt == 0) break;
        ans += cnt;
    }
    return ans;
}

int main()
{
    int t, cas = 1, x, y, c, B, D;
    cin >> t;
    while(t--){
        cin >> n;
        N = 2 * n + 1;
        for(int i = 1; i <= n; i++){
            cin >> c;
            edg[i][i + n] += c;
        }
        cin >> m;
        while(m--){
            cin >> x >> y >> c;
            edg[x + n][y] += c;
        }
        cin >> B >> D;
        for(int i = 0; i < B+D; i++){
            int u;
            cin >> u;
            if(i < B){
                edg[0][u] = inf;
            }
            else{
                edg[u + n][N] = inf;
            }
        }
        printf("Case %d: %d\n", cas++, flow());

        memset(edg, 0, sizeof edg);
    }
    return 0;
}
