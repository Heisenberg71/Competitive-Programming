#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define mod 1000000007
#define nl '\n'
using namespace std;

int arr[LIM];
ll dp[LIM], getPrev[LIM];

int main()
{
    int n;

    cin >> n;

    arr[0] = -1;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

//    dp[0] = 1;
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j < i; j++){
//            if(arr[j + 1] == arr[i] && arr[j] != arr[i])  dp[i] = (dp[i] + dp[j]) %mod;
//        }
//        cout << dp[i] << " ";
//    }
//    cout << nl;

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        //cout << "get: " << getPrev[ arr[i] ] << nl;
        dp[i] = getPrev[ arr[i] ];
        if(arr[i - 1] != arr[i]){
            dp[i] = (dp[i] + dp[i - 1]) %mod;
            getPrev[ arr[i] ] = dp[i];
        }
//        cout << dp[i] << " ";
    }
//    cout << nl;

    cout << dp[n] << nl;

    return 0;
}
