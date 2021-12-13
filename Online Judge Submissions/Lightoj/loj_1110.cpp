#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[105][105];
string a, b, str[105][105];
ll f()
{
    ll i, j;
    for(i = 0; i < 105; i++)
        for(j = 0; j < 105; j++)
            str[i][j].clear();
    for(i = 1; i <= a.size(); i++){
        for(j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                str[i][j] += str[i-1][j-1] + a[i-1];
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                dp[i][j] = dp[i][j-1];
                str[i][j] += str[i][j-1];
            }
            else if(dp[i][j-1] < dp[i-1][j]){
                dp[i][j] = dp[i-1][j];
                str[i][j] += str[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
                str[i][j] = min(str[i-1][j],str[i][j-1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}
int main()
{
    ll t, cas = 1;
    cin >> t;
    while(t--){
        cin >> a >> b;
        printf("Case %lld: ", cas++);
        if(f()) cout << str[a.size()][b.size()] << endl;
        else cout << ":(" << endl;
    }
    return 0;
}
