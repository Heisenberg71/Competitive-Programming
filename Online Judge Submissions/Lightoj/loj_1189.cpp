#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> ans;
ll fac[25];
void make_fac()
{
    fac[0] = 1;
    for(ll i = 1; i <= 20; i++)
        fac[i] = i*fac[i-1];
}
int main()
{
    make_fac();
    ll t, cas = 1, i, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 20; i >= 0; i--)
            if(fac[i] <= n) n -= fac[i], ans.pb(i);
        printf("Case %lld: ", cas++);
        if(!n){
            for(i = ans.size()-1; i >= 0; i--){
                printf("%lld!", ans[i]);
                if(i != 0) cout << "+";
                else cout << endl;
            }
        }
        else cout << "impossible" << endl;
        ans.clear();
    }
    return 0;
}
