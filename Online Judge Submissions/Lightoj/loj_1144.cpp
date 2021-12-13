#include <bits/stdc++.h>
#define ll long long
#define LIM 1000005
using namespace std;
ll status[LIM];
ll make(ll m, ll n)
{
    ll i, j, cnt;
    memset(status,0,sizeof status);
    for(i = 2; i <= m; i++){
        if(!status[i]){
            for(j = i+i; j <= m; j += i){
                status[j]++;
            }
        }
    }
    for(i = 2; i <= m; i++){
        if(!status[i]){
            for(j = i*i, cnt = 1; j*cnt <= m; cnt++)
                status[j*cnt] = -1;
        }
    }
    ll ans = 0;
    for(i = 2; i <= m; i++){
        if(status[i] == -1) ans += 0;
        else if(status[i] == 0) ans -= (n/i)*(m/i);
        else if(status[i]%2 == 0) ans += (n/i)*(m/i);
        else ans -= (n/i)*(m/i);
    }
    return m*n+ans+2;
}
int main()
{
    ll n, m, cas = 1, t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        if(n < m) swap(m,n);
        printf("Case %lld: ", cas++);
        if(m == 0 and n == 0) cout << 0 << endl;
        else if(m == 0) cout << 1 << endl;
        else cout << make(m,n) << endl;
    }
    return 0;
}
