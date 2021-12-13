#include <bits/stdc++.h>
#define ll long long
#define LIM 30005
using namespace std;
int n, dp[LIM];
struct abc{
    int lowest, cover, profit;
}arr[LIM];

bool cmp(abc x, abc y)
{
    return x.lowest < y.lowest;
}

int ub(int val)
{
    int lo = 0, hi = n, md;
    while(lo < hi){
        md = (lo+hi)/2;
        if(val < arr[md].lowest) hi = md;
        else lo = md+1;
    }
    return lo;
}

int f(int in)
{
    if(in == n) return 0;
    if(dp[in] != -1) return dp[in];

    int a, b;
    a = arr[in].profit + f(ub(arr[in].lowest + arr[in].cover - 1));
    b = f(in+1);

    return dp[in] = max(a, b);
}

int main()
{
    int t, cas = 1, i, x, y, z;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &z);
            arr[i].lowest = x;
            arr[i].cover = y;
            arr[i].profit = z;
        }
        sort(arr, arr+n, cmp);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cas++, f(0));
    }
    return 0;
}
