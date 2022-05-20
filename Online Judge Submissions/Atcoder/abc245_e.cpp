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

int A[LIM], B[LIM], C[LIM], D[LIM];

struct bc{
    int typ, wid, len;
};

vector <bc> v;
multiset <int> ms;
multiset <int> :: iterator it;

bool cmp(bc x, bc y)
{
    if(x.wid == y.wid) return x.typ < y.typ;
    return x.wid < y.wid;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> B[i];
    for(int i = 0; i < m; i++)
        cin >> C[i];
    for(int i = 0; i < m; i++)
        cin >> D[i];

    for(int i = 0; i < n; i++)
        v.pb({0, A[i], B[i]});
    for(int i = 0; i < m; i++)
        v.pb({1, C[i], D[i]});

    sort(v.begin(), v.end(), cmp);

//    for(int i = 0; i < n + m; i++)
//        cout << v[i].typ << " " << v[i].wid << " " << v[i].len << nl;

    bool ans = 1;
    for(int i = n + m - 1; i >= 0; i--){
        if(v[i].typ == 0){
            it = ms.lower_bound(v[i].len);
            if(it != ms.end()) ms.erase(it);
            else{
                ans = 0;
                break;
            }
        }
        else{
            ms.insert(v[i].len);
        }
    }

    if(ans) cout << "Yes" << nl;
    else cout << "No" << nl;


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
