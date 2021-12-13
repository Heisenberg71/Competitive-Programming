#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
ll n, m, vis[15][15], vis2[15][15], visited[15][15];
ll xx[] = {1, 2, 2, 1, -1, -2, -2, -1};
ll yy[] = {2, 1, -1, -2, -2, -1, 1, 2};
char grid[15][15];
queue <pair<ll,ll> > q;
bool inside(ll x, ll y)
{
    if(x >= 0 and y >= 0 and x < n and y < m)
        return 1;
    return 0;
}
void bfs(ll x, ll y, ll jump)
{
    memset(vis,127,sizeof(vis));
    q.push({x,y});
    vis[x][y] = 0;
    while(!q.empty()){
        ll topx = q.front().ff, topy = q.front().ss; q.pop();
        for(ll i = 0; i < 8; i++){
            ll one = topx + xx[i];
            ll two = topy + yy[i];
            if(inside(one,two) and vis[topx][topy] < vis[one][two]){
                vis[one][two] = 1 + vis[topx][topy];
                q.push({one,two});
            }
        }
    }
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(vis[i][j] < 100000) vis2[i][j] += (vis[i][j]+jump-1)/jump, visited[i][j]++;
}
int main()
{
    ll t, cas = 1, i, j;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin >> grid[i][j];
        memset(vis2,0,sizeof(vis2));
        memset(visited,0,sizeof(visited));
        ll cnt = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(grid[i][j] != '.') bfs(i,j,grid[i][j]-'0'), cnt++;
        ll mn = 1e9;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(visited[i][j] == cnt) mn = min(mn,vis2[i][j]);
        if(mn == 1e9) printf("Case %lld: -1\n", cas++);
        else printf("Case %lld: %lld\n", cas++, mn);
    }
    return 0;
}
