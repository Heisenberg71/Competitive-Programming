#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[100005][5], dp[100005][5];
ll f()
{
    ll i, j, k;

    for(i = n-1; i >= 0; i--){
        for(j = 0; j < 3; j++){
            if(i+1 == n) dp[i][j] = arr[i][j];
            else{
                ll mx = 0;
                for(k = 0; k < 3; k++){
                    if(j != k){
                        mx = max(mx,arr[i][j]+dp[i+1][k]);
                    }
                }
                dp[i][j] = mx;
            }
        }
    }

    return max(dp[0][0],max(dp[0][1],dp[0][2]));
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    cout << f() << endl;
    return 0;
}
