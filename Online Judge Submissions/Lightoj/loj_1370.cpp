#include <bits/stdc++.h>
#define ll long long
#define LIM 10000000
#define pb push_back
using namespace std;
bool status[LIM+5];
vector <ll> v;
void make_prime()
{
    ll i, j;
    status[0] = status[1] = 1;
    for(i = 4; i < LIM; i+=2)
        status[i] = 1;
    for(i = 3; i*i <= LIM; i++){
        if(status[i] == 0){
            for(j = i*i; j <= LIM; j+= i+i)
                status[j] = 1;
        }
    }
    for(i = 0; i <= LIM; i++) if(status[i] == 0) v.pb(i);
}
ll lb(ll x)
{
    ll lo = 0, hi = v.size(), md;
    while(lo<hi){
        md = (lo+hi)/2;
        if(x <= v[md]) hi = md;
        else lo = md+1;
    }
    return v[lo];
}
int main()
{
    make_prime();
    ll n, t, cas = 1, i, x, tot;
    cin >> t;
    while(t--){
        cin >> n;
        tot = 0;
        while(n--){
            cin >> x;
            tot += lb(x+1);
        }
        printf("Case %lld: %lld Xukha\n", cas++, tot);
    }
    return 0;
}
