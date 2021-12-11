#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 10000005
using namespace std;
ll n, p, phi[LIM];
void make_phi()
{
    ll i, j;
    for(i = 1; i < LIM; i++)
        phi[i] = i;

    for(i = 2; i < LIM; i++){
        if(phi[i] == i){
            for(j = i; j < LIM; j += i)
                phi[j] = (phi[j]/i) *(i - 1);
        }
    }

    for(i = 2; i < LIM; i++)
        phi[i] += phi[i-1];
}
ll bs()
{
    ll lo = 0, hi = n+1; /// ELEMENTS OF THE ARRAY MUST CONTAIN FROM [0 TO N-1] INDESES
    while(lo+1 < hi){
        ll md = (lo+hi)/2;
        if(phi[n/md] >= p) /// THE CONDITION FOR TRUE
            lo = md;
        else
            hi = md;
    }
    if(lo == 0) return -1;
    return lo;
}
int main()
{
    make_phi();
    ll t, cas = 1;
    cin >> t;
    while(t--){
        scanf("%lld %lld", &n, &p);
        printf("Case %lld: %lld\n",cas++, bs());
    }
    return 0;
}
