#include <bits/stdc++.h>
#define ll long long
#define LIM 10005
#define inf 1000000009
#define pb push_back
#define ff first
#define ss second
#define piii pair<int, pair<int, int> >
#define mp make_pair
using namespace std;

int n, m, k, d, vis[LIM][15];
vector <int> vec[LIM], wei[LIM];
vector <bool> typ[LIM];

int dj()
{
    priority_queue <piii, vector <piii>, greater<piii> > pq;

    int mn = inf;
    pq.push(mp(0, mp(0, 0))); /// dis, node, used proposed node
    vis[0][0] = 0;
    while(!pq.empty()){
        piii u = pq.top(); pq.pop();
        for(int i = 0; i < vec[u.ss.ff].size(); i++){
            int v = vec[u.ss.ff][i];
            int w = u.ff + wei[u.ss.ff][i];
            int used = u.ss.ss + typ[u.ss.ff][i];
            if(used <= d && w < vis[v][used]){
                if(v == n-1) mn = min(mn, w);
                vis[v][used] = w;
                pq.push(mp(w, mp(v, used)));
            }
        }
    }


    return mn;
}

int main()
{
    int t, cas = 1, x, y, w;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= d; j++) vis[i][j] = inf;
            vec[i].clear(), wei[i].clear(), typ[i].clear();
        }
        while(m--){
            scanf("%d %d %d", &x, &y, &w);
            vec[x].pb(y); wei[x].pb(w); typ[x].pb(0);
        }
        while(k--){
            scanf("%d %d %d", &x, &y, &w);
            vec[x].pb(y); wei[x].pb(w); typ[x].pb(1);
        }
        int ans = dj();
        printf("Case %d: ", cas++);
        if(ans == inf) printf("Impossible\n");
        else printf("%d\n", ans);

    }

    return 0;
}
