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
    for(i = 4; i <= LIM; i += 2)
        status[i] = 1;
    for(i = 3; i*i <= LIM; i++){
        if(status[i] == 0){
            for(j = i*i; j <= LIM; j += i+i){
                status[j] = 1;
            }
        }
    }
    for(i = 0; i <= LIM; i++) if(status[i] == 0) v.pb(i);
}
ll fac(ll n)
{
    ll i, ans = 1, cnt;
    for(i = 0; v[i]*v[i] <= n and i < v.size(); i++){
        cnt = 0;
        while(n%v[i] == 0){
            n /= v[i];
            cnt++;
        }
        if(cnt and v[i] != 2) ans *= (cnt+1);
    }
    if(n != 1) ans *= 2;
    return ans-1;
}
int main()
{
    make_prime();
    ll t, n, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 2) printf("Case %lld: %lld\n", cas++, 0);
        else printf("Case %lld: %lld\n", cas++, fac(n));
    }
    return 0;
}
