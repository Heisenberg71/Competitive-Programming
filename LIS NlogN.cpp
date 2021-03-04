#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll dp[100005], grid[100005];
vector <ll> arr;
int main()
{
    ll n, i, j, maxi, pos;
    while(scanf("%lld", &n) != EOF)
        arr.pb(n);
    n = arr.size();
    for(i = n-1; i >= 0; i--){
        maxi = 0;
        for(j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                if(maxi <= dp[j]){
                    maxi = dp[j];
                    grid[i] = j;
                }
            }
        }
        dp[i] = maxi+1;
    }
    maxi = 0;
    for(i = 0; i < n; i++){
        if(maxi < dp[i]){
            maxi = dp[i];
            pos = i;
        }
    }
    //cout << maxi << endl;
    //cout << "-" << endl;
    printf("%lld\n-\n", maxi);
    while(grid[pos] != 0){
        //cout << arr[pos] << endl;
        printf("%lld\n", arr[pos]);
        pos = grid[pos];
    }
    //cout << arr[pos] << endl;
    printf("%lld\n", arr[pos]);

    return 0;
}
