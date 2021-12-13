#include <bits/stdc++.h>
#define ll long long
#define LIM 30005
using namespace std;

int arr[LIM];

int build(int st, int ed)
{
    if(st == ed){
        return arr[st];
    }

    int L = (st + ed) / 2, R = (st + ed) / 2 + 1;
    int mn = min(arr[L], arr[R]), ans = 2 * mn;
    while(L > st || R < ed){
        if(L > st && R < ed){
            if(arr[L - 1] < arr[R + 1]){
                mn = min(mn, arr[R + 1]);
                R++;
            }
            else{
                mn = min(mn, arr[L - 1]);
                L--;
            }
        }
        else if(L > st){
            mn = min(mn, arr[L - 1]);
            L--;
        }
        else{
            mn = min(mn, arr[R + 1]);
            R++;
        }
        ans = max(ans, mn * (R - L + 1));

    }

    return max(ans, max(build(st, (st + ed) / 2), build((st + ed) / 2 + 1, ed)));
}

int main()
{
    int t, cas = 1, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Case %d: %d\n", cas++, build(0, n - 1));
    }
    return 0;
}
