#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf (1<<30)
#define LIM 300005
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector <ll> v;
ll sod(string s, ll num)
{
    ll rem = 0;
    for(ll i = 0; i < s.size(); i++){
        rem *= 10;
        rem += (s[i]-'0');
        rem %= num;
    }
    return rem;
}
int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t, i, cas = 1, cnt[15];
    string a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        ll a_rem = sod(a,9LL);
        memset(cnt,0,sizeof cnt);
        i = 0;
        ll tem = a_rem;
        //v.pb(1); cnt[1] = 1;
        while(!cnt[tem]){
            v.pb(tem);
            cnt[tem] = 1;
            //cout << tem << endl;
            tem = (tem*a_rem)%9;
        }
        ll sz = v.size();
        ll b_rem = sod(b,sz);

        ll aa = 1;
        for(i = 0; i < a.size(); i++)
            if(a[i] != '0') aa = 0;

        ll bb = 1;
        for(i = 0; i < b.size(); i++)
            if(b[i] != '0') bb = 0;

        printf("Case %lld: ", cas++);

        if(aa) cout << 0 << endl;
        else if(bb) cout << 1 << endl;
        else{
            b_rem--;
            if(b_rem < 0) b_rem = sz-1;
            if(v[b_rem] != 0) cout << v[b_rem] << endl;
            else cout << 9 << endl;
        }
        v.clear();
    }



    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/

