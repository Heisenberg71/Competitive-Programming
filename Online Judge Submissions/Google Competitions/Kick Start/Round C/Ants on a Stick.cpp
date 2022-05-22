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

int arr[LIM], dr[LIM];
vector <pii> v, place, v2;

bool cmp(pii x, pii y)
{
    if(x.ff == y.ff) return x.ss < y.ss;
    return x.ff < y.ff;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    int t, n, len, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> len;
        for(int i = 0; i < n; i++){
            int pos, dr;
            cin >> pos >> dr;
            place.pb({pos, i + 1});
            if(dr == 0){
                v.pb({pos, dr});
            }
            else{
                v.pb({len - pos, dr});
            }
        }
        sort(v.begin(), v.end(), cmp);
        sort(place.begin(), place.end(), cmp);

        for(int i = 0, L = 0, R = n - 1; i < n; i++){
            if(v[i].ss == 0) v2.pb({v[i].ff, place[L].ss}), L++;
            else v2.pb({v[i].ff, place[R].ss}), R--;
        }

        sort(v2.begin(), v2.end(), cmp);

        printf("Case #%d: ", cas++);
        for(int i = 0; i < v2.size(); i++)
            cout << v2[i].ss << " ";
        cout << nl;

        v.clear();
        place.clear();
        v2.clear();
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
