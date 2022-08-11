#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl '\n'
using namespace std;

int parent[LIM][22];

int main()
{
    int n, q;
    cin >> n >> q;

    memset(parent, -1, sizeof parent);

    for(int i = 2; i <= n; i++)
        cin >> parent[i][0];

    for(int i = 1; i <= 20; i++){
        for(int u = 1; u <= n; u++){
            if(parent[u][i - 1] != -1)
                parent[u][i] = parent[ parent[u][i - 1] ][i - 1];
        }
    }

    while(q--){
        int x, k;
        cin >> x >> k;

        int ans = x;
        for(int i = 0; i <= 22; i++){
            if(k&(1 << i)) ans = parent[ans][i];
            if(ans == -1) break;
        }

        cout << ans << nl;
    }

    return 0;
}
