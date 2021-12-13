#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
ll row, col, vis[505][505], cnt, ans[505][505];
char grid[505][505];
ll xx[] = {1, 0, -1, 0};
ll yy[] = {0, 1, 0, -1};
vector <pair<ll,ll> > v;
bool inside(ll x, ll y)
{
    if(x >= 0 and y >= 0 and x < row and y < col)
        return 1;
    return 0;
}
void dfs(ll x, ll y)
{   //cout << x << " " << y << endl;
    if(!inside(x,y) or grid[x][y] == '#' or vis[x][y]) return;
    if(grid[x][y] == 'C') cnt++;
    vis[x][y] = 1;
    v.pb({x,y});
    for(ll i = 0; i < 4; i++)
        dfs(x+xx[i],y+yy[i]);
}
int main()
{
    ll t, cas = 1, q, i, j, x, y;
    cin >> t;
    while(t--){
        cin >> row >> col >> q;
        getchar();
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++)
                scanf("%c", &grid[i][j]);
            getchar();
        }
        printf("Case %lld:\n", cas++);
        memset(ans,0,sizeof(ans)); //cout << "sdf" << endl;
        while(q--){//cout << "sdf" << endl;
            cin >> x >> y; //cout << "sdf" << endl;
            x--, y--;
            dfs(x,y);
            for(i = 0; i < v.size(); i++)
                ans[v[i].ff][v[i].ss] = cnt;

            printf("%lld\n", ans[x][y]);
            cnt = 0; v.clear();
        }
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
