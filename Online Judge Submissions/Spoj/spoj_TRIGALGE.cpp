#include <bits/stdc++.h>
#define ll long long
using namespace std;
double bs(ll a, ll b, ll c)
{
    double lo = 0, hi = 1e12, md;
    ll loop = 100;
    while(loop--){
        md = (lo+hi)/2;
        if(a*md + b*sin(md) < c) lo = md;
        else hi = md;
    }
    return md;
}
int main()
{
    ll t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        printf("%0.8lf\n", bs(a,b,c));
    }
    return 0;
}
