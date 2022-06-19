#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define nl "\n"
using namespace std;

int pr[LIM], sz[LIM];

int findP(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = findP(pr[u]);
}

int main()
{
    int n, t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            pr[i] = i;
            sz[i] = 1;
        }
        ll ans  = 0;
        for(int i = n; i > 0; i--){
            for(int j = i + i; j <= n; j += i){
                int u = findP(i);
                int v = findP(j);
                if(u != v){
                    ans += i;
                    if(sz[u] < sz[v]){
                        pr[u] = v;
                        sz[v] += sz[u];
                    }
                    else{
                        pr[v] = u;
                        sz[u] += sz[v];
                    }
                }
            }
        }
        printf("Case %d: %lld\n", cas++, ans);
    }

    return 0;
}
