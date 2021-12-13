#include<bits/stdc++.h>
#define ll long long
#define eps 1e-9
using namespace std;
int main()
{
    ll t, n, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        double sum = 0.0;
        for(i = 1; i <= n; i++)
            sum += 1.0/i;
        printf("Case %lld: %0.10lf\n", cas++, n*sum+eps);
    }
    return 0;
}
