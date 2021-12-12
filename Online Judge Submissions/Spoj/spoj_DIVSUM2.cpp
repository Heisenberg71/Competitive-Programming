#include <bits/stdc++.h>
#define ll long long
#define LIM 100000000
#define pb push_back
using namespace std;
ll status[LIM+5];
vector <ll> v;
void make_prime()
{
    ll i, j;

    status[0] = status[1] = 1;
    for(i = 4; i <= LIM; i+=2)
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
ll divi(ll n)
{
    ll i, ans = 1;

    for(i = 0; v[i]*v[i] <= n; i++){
        ll cnt = 0;
        while(n%v[i] == 0){
            n /= v[i];
            cnt++;
        }
        //cout << v[i] << " " << cnt << endl;
        ll tem = 1;
        cnt++;
        while(cnt--)
            tem *= v[i];
        //cout << tem << " " << v[i] << endl;
        ans *= (tem-1)/(v[i]-1);
    }
    if(n != 1) ans *= (n+1);
    return ans;
}
int main()
{
    make_prime();
    ll t, n;
    //cin >> t;
    scanf("%lld", &t);
    while(t--){
        //cin >> n;
        scanf("%lld", &n);
        //cout << divi(n)-n << endl;
        printf("%lld\n", divi(n)-n);
    }
    return 0;
}

