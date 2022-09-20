#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl '\n'
using namespace std;

int parent[LIM][32];

void build(int n)
{
    for(int i = 1; i < 32; i++){
        for(int j = 1; j <= n; j++){
            parent[j][i] = parent[ parent[j][i - 1] ][i - 1];
        }
    }
}

int findAns(int x, int k)
{
    int u = x;
    for(int i = 0; i < 32; i++){
        if((1 << i)&k) u = parent[u][i];
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int u;
        cin >> u;
        parent[i][0] = u;
    }

    build(n);

    while(q--){
        int x, k;
        cin >> x >> k;
        cout << findAns(x, k) << nl;
    }

    return 0;
}
