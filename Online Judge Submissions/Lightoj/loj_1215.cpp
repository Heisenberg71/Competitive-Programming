#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector <pair<ll,ll> > v[5];
void divi(ll pos, ll n)
{
    ll i, cnt;
    for(i = 2; i*i <= n; i++){
        cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(cnt) v[pos].pb({i,cnt});
    }
    if(n != 1) v[pos].pb({n,1});
}
ll power(ll n, ll p)
{
    ll ans = 1;
    while(p--)
        ans *= n;
    return ans;
}
int main()
{
    ll t, a, b, l, cas = 1, num, i, j, maxi;
    cin >> t;
    while(t--){
        cin >> a >> b >> l;
        printf("Case %lld: ", cas++);
        if(l%a != 0 or l%b != 0){
            cout << "impossible" << endl;
            continue;
        }
        divi(0,a);
        divi(1,b);
        divi(2,l);
//        for(i = 0; i < 3; i++){
//            for(j = 0; j < v[i].size(); j++){
//                cout << v[i][j].ff << " " << v[i][j].ss << endl;
//            }
//            cout << endl;
//        }
        num = 1;
        for(i = 0; i < v[2].size(); i++){
            maxi = 0;
            for(j = 0; j < v[0].size(); j++){
                if(v[2][i].ff == v[0][j].ff) maxi = max(maxi,v[0][j].ss);
            }
            for(j = 0; j < v[1].size(); j++){
                if(v[2][i].ff == v[1][j].ff) maxi = max(maxi,v[1][j].ss);
            }
            //cout << v[2][i].ff << " " << maxi << endl;
            if(maxi != v[2][i].ss){
                num *= power(v[2][i].ff,v[2][i].ss);
            }
        }
        cout << num << endl;
        for(i = 0; i < 5; i++)
            v[i].clear();
    }
    return 0;
}
