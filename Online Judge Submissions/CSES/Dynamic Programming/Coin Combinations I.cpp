#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
#define mod 1000000007
#define nl "\n"
using namespace std;

int c[LIM], dp[LIM];

int main()
{
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> c[i];

    dp[x] = 1;
    for(int i = x - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i + c[j] <= x){
                dp[i] += dp[ i + c[j] ];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[0] << nl;

    return 0;
}
