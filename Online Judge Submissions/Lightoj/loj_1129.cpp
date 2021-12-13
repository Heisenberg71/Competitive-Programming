#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <string> str;
vector <ll> v;
ll bs(ll val)
{
    ll lo = 0, hi = v.size()-1, md;
    while(lo <= hi){
        md = (lo+hi)/2;
        if(val == v[md]) return 1;
        else if(val < v[md]) hi = md-1;
        else lo = md+1;
    }
    return 0;
}
int main()
{
    ll t, cas = 1, n, i, j;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        ll f = 1;
        for(i = 0; i < n; i++){
            cin >> s;
            ll val = 0, base = 31;
            for(j = 0; j < s.size(); j++){
                val += (s[j] - '0' + 1)*base;
                base = (base*31);
            }
            v.pb(val);
            str.pb(s);
        }
        sort(v.begin(), v.end());
        for(i = 0; i < n; i++){
            ll val = 0, base = 31;
            for(j = 0; j < str[i].size()-1; j++){
                val += (str[i][j] - '0' + 1)*base;
                base = (base*31);
                if(bs(val)) f = 0;
            }
        }
        printf("Case %lld: ", cas++);
        if(f) printf("YES\n");
        else printf("NO\n");

        str.clear(); v.clear();
    }
    return 0;
}

