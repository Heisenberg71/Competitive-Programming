#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n, m, val[105], last, ans;
vector <int> v[10005];

void dfs(int nd)
{
    int mx_nd = -1, mx = -1;
    ans += val[nd];

    for(int i = 0; i < v[nd].size(); i++){
        if(mx < val[v[nd][i]]){
            mx = val[v[nd][i]];
            mx_nd = v[nd][i];
        }
    }

    if(mx_nd != -1){
        last = mx_nd;
        //ans += mx;
        dfs(last);
    }
}

int main()
{
    int cas = 1, t, i, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i = 0; i < n; i++)
            cin >> val[i];
        while(m--){
            cin >> x >> y;
            v[x].pb(y);
        }
        ans = 0;
        dfs(0);
        printf("Case %d: %d %d\n", cas++, ans, last);

        for(i = 0; i < n; i++)
            v[i].clear();

    }
    return 0;
}
