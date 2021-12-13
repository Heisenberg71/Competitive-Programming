#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll two(ll n)
{
    ll tem = 2, cnt = 0;
    while(n >= tem){
        cnt += n/tem;
        tem *= 2;
    }
    return cnt;
}
ll five(ll n)
{
    ll tem = 5, cnt = 0;
    while(n >= tem){
        cnt += n/tem;
        tem *= 5;
    }
    return cnt;
}
ll twoo(ll n)
{
    ll cnt = 0;
    while(n%2 == 0){
        cnt++;
        n /= 2;
    }
    return cnt;
}
ll fivee(ll n)
{
    ll cnt = 0;
    while(n%5 == 0){
        cnt++;
        n /= 5;
    }
    return cnt;
}
int main()
{
    ll tt, n, r, p, q, cas = 1, t, f;
    cin >> tt;
    while(tt--){
        cin >> n >> r >> p >> q;
        t = two(n)-two(r)-two(n-r);
        f = five(n)-five(r)-five(n-r);
        t += twoo(p)*q;
        f += fivee(p)*q;
        printf("Case %lld: %lld\n", cas++, min(t,f));
    }
    return 0;
}
