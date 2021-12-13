#include <bits/stdc++.h>
#define ll long long
#define val 0.577215664901532
using namespace std;
int main()
{
    ll t, i,  cas = 1, n;
    double x, arr[105];
    arr[0] = 0.0;
    for(i = 1; i < 105; i++)
        arr[i] = arr[i-1] + 1.0/i;
    cin >> t;
    while(t--){
        cin >> n;
        x = log(n)+val+1/(2.0*n)-1/(12.0*n*n);
        if(n < 100) printf("Case %lld: %0.10lf\n", cas++, arr[n]);
        else printf("Case %lld: %0.10lf\n", cas++, x);
    }
    return 0;
}
