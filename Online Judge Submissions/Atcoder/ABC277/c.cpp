#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 400005
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
using namespace std;

vector <pii> v;
vector <int> edge[LIM];
set <int> s;
set <int> :: iterator it;
map <int, int> comp, reall;
bool vis[LIM];

int dfs(int u)
{
    vis[u] = 1;
    int mx = reall[u];
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!vis[v]) mx = max(mx, dfs(v));
    }
    return mx;
}

int main()
{
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        v.pb({x, y});
    }

    int cnt = 1;
    for(it = s.begin(); it != s.end(); it++, cnt++){
        comp[*it] = cnt;
        reall[cnt] = *it;
    }

    for(int i = 0; i < n; i++){
        edge[ comp[ v[i].ff ] ].pb(comp[ v[i].ss ]);
        edge[ comp[ v[i].ss ] ].pb(comp[ v[i].ff ]);
    }

    if(!comp[1]) cout << 1 << nl;
    else cout << dfs(1) << nl;

    return 0;
}

