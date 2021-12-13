#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> edge[30005], wei[30005];
ll vis[30005];
void dfs(ll node)
{
    for(ll i = 0; i < edge[node].size(); i++){
        if(vis[edge[node][i]] == -1){
            vis[edge[node][i]] = vis[node] + wei[node][i];
            dfs(edge[node][i]);
        }
    }
}
int main()
{
    ll t, i, cas = 1, x, y, w, n;
    cin >> t;
    while(t--){
        scanf("%lld", &n);
        for(i = 0; i < n-1; i++){
            scanf("%lld %lld %lld", &x, &y, &w);
            edge[x].pb(y); wei[x].pb(w);
            edge[y].pb(x); wei[y].pb(w);
            vis[i] = -1;
        }
        vis[n-1] = -1;
        vis[0] = 0; //cout << "sdf" << endl;
        dfs(0); //cout << "sdf" << endl;
        ll mxdis = 0, point;
        for(i = 0; i < n; i++){
            if(mxdis < vis[i]){
                mxdis = vis[i];
                point = i;
            }
            vis[i] = -1;
        }//cout << point << endl;
        vis[point] = 0, dfs(point); //cout << "sd" << endl;
        mxdis = 0;
        for(i = 0; i < n; i++)
            mxdis = max(mxdis,vis[i]);
        printf("Case %lld: %lld\n", cas++, mxdis);
        for(i = 0; i < n; i++)
            edge[i].clear(), wei[i].clear();
    }
    return 0;
}
