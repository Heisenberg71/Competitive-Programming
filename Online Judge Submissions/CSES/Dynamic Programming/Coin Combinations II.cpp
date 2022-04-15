#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define mod 1000000007
#define nl "\n"
using namespace std;

int n, x;
int c[LIM], dp[102][LIM];

int fun()
{
    dp[n][0] = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= x; j++){
            int a = 0, b = 0;
            if(j >= c[i]) a = dp[i][ j - c[i] ];
            b = dp[i + 1][j];
            dp[i][j] = (a + b)%mod;
        }
    }

    return dp[0][x];
}

int main()
{
    FAST_IO();

    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> c[i];

    cout << fun() << nl;

    return 0;
}
