#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
using namespace std;
int main()
{
    ll t, cas = 1, tiger, deer;
    cin >> t;
    while(t--){
        cin >> tiger >> deer;
        if(tiger%2) printf("Case %lld: 0\n", cas++);
        else printf("Case %lld: %0.10lf\n", cas++, 1.0/(tiger+1)+eps);
    }
    return 0;
}
