#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
ll r, c, vis[2][205][205];
ll xx[] = {1, 0, -1, 0};
ll yy[] = {0, 1, 0, -1};
char grid[205][205];
queue <pair<ll,ll> > q;
vector <pair<ll,ll> > v;
bool inside(ll x, ll y)
{
    if(x >= 0 and y >= 0 and x < r and y < c)
        return 1;
    return 0;
}
void bfs(ll f, ll x, ll y)
{
    if(f == 1){
        for(ll i = 0; i < v.size(); i++){
            vis[f][v[i].ff][v[i].ss] = 0;
            q.push({v[i].ff,v[i].ss});
        }
    }
    else q.push({x,y}); vis[f][x][y] = 0;
    while(!q.empty()){
        ll topx = q.front().ff, topy = q.front().ss;
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll a = topx+xx[i];
            ll b = topy+yy[i];
            if(inside(a,b) and vis[f][topx][topy]+1 < vis[f][a][b] and grid[a][b] != '#'){
                vis[f][a][b] = 1+vis[f][topx][topy];
                q.push({a,b});
            }
        }
    }
}
int main()
{
    ll t, i, cas = 1, j, k;
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(i = 0; i < 2; i++)
            for(j = 0; j < r; j++)
                for(k = 0; k < c; k++)
                    vis[i][j][k] = 1e9;
        ll storex, storey;
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'J') storex = i, storey = j;
                if(grid[i][j] == 'F') v.pb({i,j});
            }
        }
        bfs(0,storex,storey);
        ll flag = 1e9;
        bfs(1,0,0);
            for(j = 0; j < r; j++){
                if(vis[0][j][0] < vis[1][j][0])
                    flag = min(flag,vis[0][j][0]);
            }
            for(j = 0; j < r; j++){
                 if(vis[0][j][c-1] < vis[1][j][c-1])
                    flag = min(flag,vis[0][j][c-1]);
            }
            for(j = 0; j < c; j++){
                if(vis[0][0][j] < vis[1][0][j])
                    flag = min(flag,vis[0][0][j]);
            }
            for(j = 0; j < c; j++){
                if(vis[0][r-1][j] < vis[1][r-1][j])
                    flag = min(flag,vis[0][r-1][j]);
            }
        printf("Case %lld: ", cas++);
        if(flag == 1e9) cout << "IMPOSSIBLE" << endl;
        else cout << flag+1 << endl;
        v.clear();
    }
    return 0;
}
