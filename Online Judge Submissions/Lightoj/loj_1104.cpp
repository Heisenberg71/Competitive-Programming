#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
using namespace std;
int main()
{
    ll t, n, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        double val = 1.0;
        ll up = n;
        while(val > 0.5+eps){
            val *= (1.0*up)/n;
            up--;
            //cout << val << endl;
        }
        //cout << val << endl;
        printf("Case %lld: %lld\n", cas++, n-up-1);
    }
    return 0;
}
