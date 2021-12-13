#include <bits/stdc++.h>
#define ll long long
#define inf 9999999999999
using namespace std;
ll dp[100005], dp2[100005], I[100005];
int main()
{
    ll n, i, j, arr[100005], t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        I[0] = -inf;
        for(i = 1; i <= n; i++)
            I[i] = inf;
        ll len, len2;
        len = len2 = 0;
        for(i = 0; i < n; i++){
            ll lo = 0, hi = n, md;
            while(lo < hi){
                md = (lo+hi)/2;
                if(arr[i] <= I[md]) hi = md;
                else lo = md+1;
            }
            I[lo] = arr[i];
            dp[i] = lo;
        }
//        for(i = 0; i < n; i++)
//            cout << dp[i] << " ";
//        cout << endl;
        reverse(arr,arr+n);
        I[0] = -inf;
        for(i = 1; i <= n; i++)
            I[i] = inf;
        for(i = 0; i < n; i++){
            ll lo = 0, hi = n, md;
            while(lo < hi){
                md = (lo+hi)/2;
                if(arr[i] <= I[md]) hi = md;
                else lo = md+1;
            }
            I[lo] = arr[i];
            dp2[i] = lo;
        }
        ll ans = 0;
        for(i = 0, j = n-1; i < n; i++, j--)
            ans = max(ans,min(dp[i],dp2[j]));
        //cout << 2*ans-1 << endl;
        printf("Case %lld: %lld\n", cas++, 2*ans-1);
    }
    return 0;
}
