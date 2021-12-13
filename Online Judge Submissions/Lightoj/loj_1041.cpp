#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct abc{
    int w, x, y;
};

int n, cnt, pr[55];
string from, to;
map <string, int> mp;
vector <abc> edg;
set<int> s;

bool cmp(abc x, abc y)
{
    return x.w < y.w;
}

int findP(int u)
{
    if(pr[u] == u) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);
    if(u != v)
        pr[u] = v;
}

int kruskal()
{
    sort(edg.begin(), edg.end(), cmp);

    for(int i = 0; i < cnt; i++)
        pr[i] = i;

    int cost = 0;
    for(int i = 0; i < edg.size(); i++){
        int u = findP(edg[i].x);
        int v = findP(edg[i].y);
        if(u != v){
            cost += edg[i].w;
            connect(u, v);
        }
    }

    for(int i = 1; i < cnt; i++){
        findP(i);
        s.insert(pr[i]);
    }

    if(s.size() == 1) return cost;
    return -1;
}

int main()
{
    int t, cas = 1, dis;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 1;
        for(int i = 0; i < n; i++){
            cin >> from >> to >> dis;
            if(!mp[from]) mp[from] = cnt++;
            if(!mp[to]) mp[to] = cnt++;
            edg.pb({dis, mp[from], mp[to]});
        }
        int ans = kruskal();
        printf("Case %d: ", cas++);
        if(ans != -1) cout << ans << endl;
        else cout << "Impossible" << endl;

        mp.clear();
        edg.clear();
        s.clear();
    }
    return 0;
}
