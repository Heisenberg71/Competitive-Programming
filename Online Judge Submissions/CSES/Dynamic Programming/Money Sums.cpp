#include <bits/stdc++.h>
#define ll long long
#define LIM 5005
#define nl "\n"
using namespace std;

int n, arr[102], dp[102][100005];
vector <int> ans;

int fun(int pos, int sum)
{
    if(sum == 0) return 1;
    if(sum < 0 || pos == n) return 0;
    if(dp[pos][sum] != -1) return dp[pos][sum];

    int a = fun(pos + 1, sum - arr[pos]);
    int b = fun(pos + 1, sum);

    return dp[pos][sum] = (a|b);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof dp);

    for(int i = 1; i < 100005; i++){
        if(fun(0, i)) ans.push_back(i);
    }

    cout << ans.size() << nl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << nl;

    return 0;
}
