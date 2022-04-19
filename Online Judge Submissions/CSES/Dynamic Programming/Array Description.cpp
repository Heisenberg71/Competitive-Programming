#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define nl "\n"
#define mod 1000000007
using namespace std;

int n, m;
int arr[LIM], dp[LIM][105];

int f(int pos, int prev)
{
    if(pos == n) return 1;
    if(pos && arr[pos] && abs(prev - arr[pos]) > 1) return 0;
    if(dp[pos][prev] != -1) return dp[pos][prev];

    int L = arr[pos], R = arr[pos];
    if(pos == 0 && arr[pos] == 0){
        L = 1;
        R = m;
    }
    else if(arr[pos] == 0){
        L = max(1, prev - 1);
        R = min(m, prev + 1);
    }

    int ans = 0;
    for(int i = L; i <= R; i++){
        ans += f(pos + 1, i);
        ans %= mod;
    }

    return dp[pos][prev] = ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof dp);
    cout << f(0, m + 1) << nl;

    return 0;
}
