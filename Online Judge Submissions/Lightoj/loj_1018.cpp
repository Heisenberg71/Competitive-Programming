#include <bits/stdc++.h>
#define pii pair <int, int>
#define inf 100000008
using namespace std;
int n, x[20], y[20], mask[17][17], dp[(1<<16)+5];
int Set(int mask, int pos) {return (mask | (1<<pos)) ;}
bool check(int mask, int pos) {return (mask & (1<<pos)) ;}
pii slop(int a, int b)
{

    int dy = y[b] - y[a];
    int dx = x[b] - x[a];
    //cout << dy << " " << dx << endl;
    int g = __gcd(dx, dy);
    //cout << g << endl;
    dy /= g, dx /= g;
    if(dx < 0){
        dx = -dx;
        dy = -dy;
    }
    return {dy, dx};
}
int f(int curr)
{
    if(curr + 1 == (1 << n)) return 0;
    if(dp[curr] != -1) return dp[curr];

    int u;
    for(u = 0; check(curr, u) && u < n; u++);

    int mn = inf;
    for(int v = 0; v < n; v++)
        mn = min(mn, 1 + f(curr | mask[u][v]));

    return dp[curr] = mn;
}
int main()
{
    int t, cas = 1, i, j, k;
    cin >> t;
    while(t--){
        cin >> n;
        memset(dp, -1, sizeof dp);
        memset(mask, 0, sizeof mask);
        for(i = 0; i < n; i++)
            cin >>  x[i] >> y[i];
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mask[i][j] = (Set(0, i) | Set(0, j));
                for(k = 0; k < n; k++){
                    if(i != j && i != k && slop(i,j) == slop(i,k)){
                        mask[i][j] = Set(mask[i][j], k);
                    }
                }
            }
        }
        //cout << "sdf" << endl;
        printf("Case %d: %d\n", cas++, f(0));

    }
    return 0;
}
