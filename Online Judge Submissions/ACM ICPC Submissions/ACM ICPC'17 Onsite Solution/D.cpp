#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int subtree[1005], vis[1005], n, k;
vector <int> nd[1005];

void dfs(int u)
{
    vis[u] = 1;
    vector <int> temp;
    //cout << temp.size() << endl;
    for(int i = 0; i < nd[u].size(); i++){
        int v = nd[u][i];
        if(!vis[v]){
            dfs(v);
            temp.pb(subtree[v]);
        }
    }
    //cout << temp.size() << " " << k << endl;
    if(temp.size() < k){
        subtree[u] = 1;
    }
    else{
        sort(temp.begin(), temp.end(), greater<int>());
        int tot = 0;
        for(int i = 0; i < k; i++){
            tot += temp[i];
            //cout << "tot: " << tot << endl;
        }
        subtree[u] = tot + 1;
    }
    //temp.clear();

}

int main()
{
    int t, cas = 1, i, x, y;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i = 0; i < n-1; i++){
            cin >> x >> y;
            nd[x].pb(y);
            nd[y].pb(x);
        }
        dfs(1);
        printf("Case %d: %d\n", cas++, subtree[1]);
        for(i = 0; i <= n; i++){
            nd[i].clear();
            vis[i] = subtree[i] = 0;
        }
    }
    return 0;
}

