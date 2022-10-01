#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 50004
using namespace std;

int arr[LIM], vis[LIM], par[LIM];
vector <int> edge[LIM];

void bfs(int u)
{
    memset(vis, 127, sizeof vis);
    queue <int> q;
    vis[u] = 0;
    q.push(u);
    while(!q.empty()){
        int u = q.front(); q.pop();
        //cout << u << endl;
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i];
            if(vis[u] + 1 < vis[v]){
                par[v] = u;
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

}

int main()
{
    int t, n, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(i){
                edge[ arr[i] ].pb(arr[i - 1]);
                edge[ arr[i - 1] ].pb(arr[i]);
            }
        }
        for(int i = 0; i < n; i++){
            sort(edge[ arr[i] ].begin(), edge[ arr[i] ].end());
        }
        bfs(arr[0]);
        printf("Case %d:\n", cas++);
        stack <int> stk;
        int u = arr[n - 1];
        while(u != arr[0]){
            //printf("%d ", u);
            stk.push(u);
            u = par[u];
        }
        //printf("%d\n", u);
        stk.push(u);

        while(!stk.empty()){
            printf("%d ", stk.top());
            stk.pop();
        }
        printf("\n");

        for(int i = 0; i < n; i++)
            edge[ arr[i] ].clear();
    }

    return 0;
}
