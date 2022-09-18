#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct Edge{
    int u, v, w;
};

int n, m, par[205], siz[205];
vector <Edge> edge;
Edge save;

int findP(int u)
{
    if(u == par[u]) return u;
    return par[u] = findP(par[u]);
}

int MST()
{
    int sz = edge.size();
    for(int i = 0; i < sz; i++){
        if(edge[i].w > save.w){
            for(int j = sz - 1; j > i; j--)
                edge[j] = edge[j - 1];
            edge[i] = save;
            break;
        }
    }

//    for(int i = 0; i < sz; i++)
//        cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;

    for(int i = 1; i <= n; i++){
        par[i] = i;
        siz[i] = 1;
    }

    int ans = 0;
    for(int i = 0; i < sz; i++){
        int uu = findP(edge[i].u);
        int vv = findP(edge[i].v);
        if(uu != vv){
            ans += edge[i].w;
            if(siz[vv] < siz[uu]){
                siz[uu] += siz[vv];
                par[vv] = uu;
            }
            else{
                siz[vv] += siz[uu];
                par[uu] = vv;
            }
        }
    }

    bool isConnected = 1;
    for(int i = 1; i <= n; i++){
        if(findP(i) != findP(1)) isConnected = 0;
    }

    if(isConnected) return ans;
    return -1;
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("Case %d:\n", cas++);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge.pb({u, v, w});
            save = {u, v, w};
            printf("%d\n", MST());
        }
        edge.clear();
    }

    return 0;
}
