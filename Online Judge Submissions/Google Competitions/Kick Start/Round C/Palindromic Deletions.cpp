#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

int n;
ll fact[LIM];

bool isPal(string str)
{
    if(str.empty()) return 1;
    string temp = str;
    reverse(temp.begin(), temp.end());
    return (str == temp);
}

ll fun(string str)
{
    if(str.size() == 0) return 1;

    ll val = 0;
    if(isPal(str)) val = fact[str.size()];

    ll ans = 0;
    for(int i = 0; i < str.size(); i++){
        string s, s2, s3;
        for(int j = 0; j < i; j++)
            s += str[j];
        for(int j = i + 1; j < str.size(); j++)
            s2 += str[j];
        s3 = s + s2;
        ans += fun(s3)%mod;
        ans %= mod;
    }

    return (ans+val)%mod;
}

void fac()
{
    fact[0] = 1;
    for(int i = 1; i <= 405; i++)
        fact[i] = (i*fact[i - 1])%mod;
}

ll bigmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = bigmod(a, b/2);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    fac();

    int t, cas = 1;
    string str;
    cin >> t;
    while(t--){
        cin >> n >> str;

        ll up = 0;
        for(int i = 0; i < str.size(); i++){
            string s, s2, s3;
            for(int j = 0; j < i; j++)
                s += str[j];
            for(int j = i + 1; j < str.size(); j++)
                s2 += str[j];
            s3 = s + s2;
//            cout << s3 << nl;
            up += fun(s3);
            up %= mod;
        }

        ll ans = (up*bigmod(fact[n], mod - 2))%mod;
        printf("Case #%d: ", cas++);
        cout << ans << nl;
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
