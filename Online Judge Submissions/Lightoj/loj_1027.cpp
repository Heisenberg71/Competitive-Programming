#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, n, x, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        ll sum = 0, cnt = 0;
        for(i = 0; i < n; i++){
            cin >> x;
            if(x > 0) cnt++;
            sum += abs(x);
        }
        if(cnt) printf("Case %lld: %lld/%lld\n", cas++, sum/__gcd(sum,cnt), cnt/__gcd(sum,cnt));
        else printf("Case %lld: inf\n", cas++);
    }
    return 0;
}
