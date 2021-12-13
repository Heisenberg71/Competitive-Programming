#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
ll grid[25][25], vis[25][25], m, n;
vector <pair<ll,ll> > v;
ll xx[] = {1, -1, 0, 0};
ll yy[] = {0, 0, 1, -1};
void bfs(ll x, ll y)
{
    queue <pair<ll,ll> > q;
    memset(vis,127,sizeof(vis));
    vis[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        ll topx = q.front().ff;
        ll topy = q.front().ss;
        q.pop();
        for(ll i = 0; i < 4; i++){
            //cout << grid[topx][topy] << endl;
            if(vis[topx][topy]+1 < vis[topx+xx[i]][topy+yy[i]] and topx+xx[i] < m and topy+yy[i] < n and
            (grid[topx+xx[i]][topy+yy[i]] == '.' or grid[topx+xx[i]][topy+yy[i]] == 'a' or
             grid[topx+xx[i]][topy+yy[i]] == 'b' or grid[topx+xx[i]][topy+yy[i]] == 'c' or
             grid[topx+xx[i]][topy+yy[i]] == 'h')){
                q.push({topx+xx[i],topy+yy[i]});
                vis[topx+xx[i]][topy+yy[i]] = vis[topx][topy]+1;
                //cout << "sd" << endl;
            }
        }
    }
}
int main()
{
    ll t, i, j, x, y, cas = 1;
    string s;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(i = 0; i < m; i++){
            cin >> s;
            for(j = 0; j < n; j++){
                grid[i][j] = s[j];
                if(grid[i][j] == 'a' or grid[i][j] == 'b' or grid[i][j] == 'c') v.pb({i,j});
                if(grid[i][j] == 'h') x = i, y = j;
            }
        }
        ll maxi = 0;
        //cout << x << " " << y << endl;
        for(ll i = 0; i < v.size(); i++){
            bfs(v[i].ff,v[i].ss);
            maxi = max(maxi,vis[x][y]);
        }
        //cout << maxi << endl;
        printf("Case %lld: %lld\n", cas++, maxi);
        v.clear();
    }
    return 0;
}
