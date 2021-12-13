#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
char grid[15][15];
ll vis[15][15], n;
pair<ll,ll> pos[30];
queue <pair<ll,ll> > q;
ll xx[] = {1, 0, -1, 0};
ll yy[] = {0, 1, 0, -1};
bool inside(ll x, ll y)
{
    if(x >= 0 and y >= 0 and x < n and y < n)
        return 1;
    return 0;
}
ll bfs(ll st)
{
    while(!q.empty()) q.pop();
    q.push(pos[st]);
    vis[pos[st].ff][pos[st].ss] = 0;
    while(!q.empty()){
        ll topx = q.front().ff, topy = q.front().ss; q.pop();
        if(grid[topx][topy]-'A' == st+1) return vis[topx][topy];
        for(ll i = 0; i < 4; i++){
            ll row = topx+xx[i], col = topy+yy[i];
            if(vis[row][col] == -1 and inside(row,col) and grid[row][col] != '#'){
                if(grid[row][col] >= 'A' and grid[row][col] <= 'Z' and grid[row][col]-'A' > st+1)
                    continue;
                vis[row][col] = 1 + vis[topx][topy];
                q.push({row, col});
            }
        }
    }
    return 0;
}
int main()
{
    ll t, cas = 1, i, j;
    cin >> t;
    while(t--){
        cin >> n;
        ll cnt = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j] >= 'A' and grid[i][j] <= 'Z')
                    pos[grid[i][j]-'A'] = {i,j}, cnt++;
            }
        }
        printf("Case %lld: ", cas++);
        ll ans = 0;
        for(i = 0; i < cnt-1; i++){
            //cout << i << endl;
            memset(vis,-1,sizeof(vis));
            ll val = bfs(i);
            if(val)
                ans += val;
            else{
                cout << "Impossible" << endl;
                break;
            }
        }
        if(i == cnt-1) cout << ans << endl;
    }
    return 0;
}
