#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, arr[1005], maxi;
ll f()
{
    ll lo = maxi, hi = 1e10, md;
    while(lo<hi){
        ///cout << lo << " " << hi << endl;
        md = (lo+hi)/2;
        ll i = 0, sum = 0, cnt = 0;
        while(i < n){
            while(i < n and sum+arr[i] <= md){
                sum += arr[i];
                i++;
            }
            sum = 0;
            cnt++;
        }
        if(cnt <= m) hi = md;
        else lo = md+1;
    }
    return lo;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        maxi = 0;
        for(i = 0; i < n; i++){
            cin >> arr[i];
            maxi = max(maxi,arr[i]);
        }
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
