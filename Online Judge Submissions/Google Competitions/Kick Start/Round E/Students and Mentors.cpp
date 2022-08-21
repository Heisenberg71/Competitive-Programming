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
#define LIM 1000006
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

int arr[LIM], freq[LIM];
vector <pii> v;

int bs(int idx, int val, int n)
{
    int lo = 0, hi = n - 1, md, ans = -1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(v[md].ff <= val + val){
            ans = md;
            lo = md + 1;
        }
        else{
            hi = md - 1;
        }
    }

    //cout << "ans: " <<  ans << nl;

    if(val != v[ans].ff) return v[ans].ff;
    if(freq[val] > 1) return v[ans].ff;
    if(ans >= 1) return v[ans - 1].ff;
    return -1;
//    else{
//        int lo = 0, hi = n - 1, md, ans = -1;
//        while(lo <= hi){
//            md = lo + (hi - lo)/2;
//            if(v[md].ff <= val){
//                ans = md;
//                lo = md + 1;
//            }
//            else{
//                hi = md - 1;
//            }
//        }
//        if(ans - 1 > 0) return v[ans - 1].ff
//        return -1;
//    }
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int t, cas = 1, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            freq[ arr[i] ]++;
            v.pb({arr[i], i});
        }
        sort(v.begin(), v.end());

        cout << "Case #" << cas++ << ": ";
        for(int i = 0; i < n; i++){
            int ans = bs(i, arr[i], n);
            cout << ans << " ";
        }
        cout << nl;

        v.clear();
        for(int i = 0; i < n; i++)
            freq[ arr[i] ] = 0;
    }

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. READ PROBLEM STATEMENT CAREFULLY.
    2. LOOK SPECIAL CASE (LIKE, N = 1).
    3. LOOK FOR OVERFLOW.
    4. LOOK FOR OUT OF BOUNDS.
    5. DO NOT STUCK WITH A SINGLE APPROACH.
    6. THINK OUT OF THE BOX.
**/
