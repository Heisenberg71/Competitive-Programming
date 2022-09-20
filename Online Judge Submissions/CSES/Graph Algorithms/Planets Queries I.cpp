#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
using namespace std;

int n, nxt[LIM], ans[LIM], vis[LIM], dist[LIM];
stack <int> stk;

void dfs(int u)
{
    stack <int> stk;
    int tim = 1;
    while(!vis[u]){
        stk.push(u);
        dist[u] = tim++;
        vis[u] = 1;
        u = nxt[u];
    }

    if(vis[u] == 1){
        int diff = tim - dist[u];
        ans[u] = diff;
        vis[u] = 2;
        while(stk.top() != u){
            ans[stk.top()] = diff;
            vis[stk.top()] = 2;
            stk.pop();
        }
    }

    while(!stk.empty()){
        vis[stk.top()] = 2;
        stk.pop();
    }
}

void dfs2(int u)
{
    stack <int> stk;
    while(!ans[u]){
        stk.push(u);
        u = nxt[u];
    }
    int x = 1;
    while(!stk.empty()){
        ans[ stk.top() ] = ans[u] + x;
        stk.pop();
        x++;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &nxt[i]);

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++){
        if(!ans[i]) dfs2(i);
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
