#include <bits/stdc++.h>
#define ll long long
#define LIM 1000000
#define pb push_back
using namespace std;
bool status[LIM+5], status2[LIM+5];
vector <ll> v;
void make_prime()
{
    ll i, j;
    status[0] = status[1] = 1;
    for(i = 4; i <= LIM; i += 2)
        status[i] = 1;
    for(i = 3; i*i <= LIM; i += 2){
        if(!status[i]){
            for(j = i*i; j <= LIM; j += i+i)
                status[j] = 1;
        }
    }
    for(i = 0; i <= LIM; i++)
        if(!status[i]) v.pb(i);
}
ll sg(ll a, ll b)
{
    ll i, j, val;
    memset(status2,0,sizeof(status2));
    //status2[0] = status2[1] = 1;
    for(i = 0; v[i]*v[i] <= b; i++){
        val = v[i]*((a+v[i]-1)/v[i]);
        for(j = val; j <= b; j += v[i]){
            if(j != v[i]) status2[j-a] = 1;
        }
    }
    ll cnt = 0;
    if(a == 1) cnt = -1;
    for(i = a; i <= b; i++)
        if(!status2[i-a]) cnt++;
    return cnt;
}
int main()
{
    make_prime();
    ll n, a, b, i, cas = 1;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a >> b;
        printf("Case %lld: %lld\n", cas++, sg(a,b));
    }
    return 0;
}
