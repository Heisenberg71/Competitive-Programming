#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, x1, y1, x2, y2, a, b, cas = 1, g;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        a = abs(y2-y1);
        b = abs(x1-x2);
        g = __gcd(a,b);
        if(a == 0 and b == 0) printf("Case %lld: 1\n", cas++);
        else if(a == 0) printf("Case %lld: %lld\n", cas++, b/(b/g)+1);
        else if(b == 0) printf("Case %lld: %lld\n", cas++, a/(a/g)+1);
        else printf("Case %lld: %lld\n", cas++, min(a/(a/g),b/(b/g))+1);
    }
    return 0;
}
