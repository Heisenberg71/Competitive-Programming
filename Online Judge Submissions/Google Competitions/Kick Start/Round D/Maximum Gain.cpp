#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define nl '\n'
using namespace std;

int n[2], k;
int prefSum[2][LIM];

ll fun(int typ, int sz)
{
    if(n[typ] <= sz) return prefSum[typ][ n[typ] ];

    int mx = 0;
    for(int i = 0; i <= sz; i++){
        mx = max(mx, prefSum[typ][i] + prefSum[typ][ n[typ] ] - prefSum[typ][ n[typ] - (sz - i) ]);
    }

    return mx;
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n[0];
        for(int i = 1; i <= n[0]; i++){
            int x;
            cin >> x;
            prefSum[0][i] = prefSum[0][i - 1] + x;
        }
        cin >> n[1];
        for(int i = 1; i <= n[1]; i++){
            int x;
            cin >> x;
            prefSum[1][i] = prefSum[1][i - 1] + x;
        }
        cin >> k;

        ll mx = 0;
        for(int i = 0; i <= k; i++){
            mx = max(mx, fun(0, i) + fun(1, k - i));
        }

        cout << "Case #" << cas++ << ": " << mx << nl;
    }

    return 0;
}
