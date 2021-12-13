#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll i, t, cas = 1, n, ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans = n + n/9;
        printf("Case %lld: ", cas++);
        if(ans%10 == 0) cout << ans-1 << " " << ans << endl;
        else cout << ans << endl;
    }
    return 0;
}
