/*
    this code was never submitted to any OJ's
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 100005
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std;

int vertex, edges, vis[LIM], dis[LIM], low[LIM], par[LIM], tim, idx;
vector <int> edg[LIM];
vector <pii> bcc[LIM];
stack <pii> stk;

void dfs(int u)
{
    dis[u] = low[u] = tim++;
    vis[u] = 1;
    int child = 0;

    for(int i = 0; i < edg[u].size(); i++){
        int v = edg[u][i];
        if(vis[v] == 0){
            child++;
            stk.push({u, v});
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(par[u] == -1 && child > 1){
                if(!stk.empty()){
                    while(!stk.empty()){
                        bcc[idx].pb(stk.top());
                        if(stk.top().ff == u && stk.top().ss == v){
                            stk.pop();
                            break;
                        }
                        stk.pop();
                    }
                    idx++;
                }
            }
            if(par[u] != -1 && low[v] >= dis[u]){
                if(!stk.empty()){
                    while(!stk.empty()){
                        bcc[idx].pb(stk.top());
                        if(stk.top().ff == u && stk.top().ss == v){
                            stk.pop();
                            break;
                        }
                        stk.pop();
                    }
                    idx++;
                }
            }
        }
        else if(par[u] != v && dis[v] < low[u]){
            low[u] = dis[v];
            stk.push({u, v});
        }
    }

    vis[u] = 2;
}

int main()
{
    int x, y;
    cin >> vertex >> edges;
    while(edges--){
        cin >> x >> y;
        edg[x].pb(y);
        edg[y].pb(x);
    }

    tim = 1;
    par[1] = -1;
    idx = 0;
    dfs(1);

    if(!stk.empty()){
        while(!stk.empty()){
            bcc[idx].pb(stk.top());
            stk.pop();
        }
        idx++;
    }

    cout << "The number of BCC in the graph: " << idx << endl;
    for(int i = 0; i < idx; i++){
        cout << "BCC No. " << i + 1 << endl;
        for(int j = 0; j < bcc[i].size(); j++)
            cout << bcc[i][j].ff << " " << bcc[i][j].ss << endl;
    }

    return 0;
}
