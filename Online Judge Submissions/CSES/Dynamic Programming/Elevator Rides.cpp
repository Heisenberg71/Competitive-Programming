#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define nl "\n"
using namespace std;

int arr[25];
pii dp[(1 << 20) + 5];

int main()
{
    int n, x;

    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = {1, 0};
    for(int s = 1; s < (1 << n); s++){
        pii mn = {n + 1, 0};
        for(int i = 0; i < n; i++){
            if(s&(1 << i)){
                int prev = (s^(1 << i));
                if(dp[prev].ss + arr[i] <= x){
                    mn = min(mn, {dp[prev].ff, dp[prev].ss + arr[i]});
                }
                else{
                    mn = min(mn, {dp[prev].ff + 1, arr[i]});
                }
            }
        }
        dp[s] = mn;
    }

    cout << dp[(1 << n) - 1].ff << nl;

    return 0;
}
