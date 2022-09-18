#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pdi pair<double, int>
#define LIM 105
using namespace std;

int n, m, s, k;
vector <int> edge[LIM], prob[LIM];
double vis[LIM];

double dijkstra()
{
    for(int i = 0; i < n; i++)
        vis[i] = 0.0;

    vis[0] = 1.0;
    priority_queue <pdi> pq;
    pq.push({1.0, 0});

    while(!pq.empty()){
        pdi u = pq.top(); pq.pop();
        if(u.ss == n - 1) return u.ff;
        for(int i = 0; i < edge[u.ss].size(); i++){
            double newProb = u.ff*(prob[u.ss][i]/100.0);
            int v = edge[u.ss][i];
            if(vis[v] < newProb){
                vis[v] = newProb;
                pq.push({newProb, v});
            }
        }
    }
}

void reset()
{
    for(int i = 0; i < n; i++){
        edge[i].clear();
        prob[i].clear();
    }
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &m, &s, &k);
        for(int i = 0; i < m; i++){
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            edge[u].pb(v), edge[v].pb(u);
            prob[u].pb(p), prob[v].pb(p);
        }
        double passProb = dijkstra();
        double failProb = 1.0 - passProb;
        double ans = (passProb*(k + k) + failProb*(k + k))/(1.0 - failProb);
        ans *= s;
        printf("Case %d: %lf\n", cas++, ans);
        reset();
    }

    return 0;
}
