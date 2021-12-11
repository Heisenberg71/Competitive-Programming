#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, dp[100005], arr[100005];
ll f()
{
    ll i, j;
    for(i = 0; i <= k; i++){
        for(j = 0; j < n; j++){
            if(arr[j] <= i and !dp[i-arr[j]])
                dp[i] = 1;
        }
    }
    return dp[k];
}
int main()
{
    ll i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    if(f()) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
