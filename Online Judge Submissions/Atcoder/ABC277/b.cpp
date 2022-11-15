#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

map <char, int> mp, mp2;
set <string> s;

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    mp[ 'H' ] = mp[ 'C' ] = mp[ 'D' ] = mp[ 'S' ] = 1;
    mp2[ 'A' ] = mp2[ 'T' ] = mp2[ 'J' ] = mp2[ 'Q' ] = mp2[ 'K' ] = 1;
    for(char ch = '2'; ch <= '9'; ch++)
        mp2[ch] = 1;

    int n;
    cin >> n;
    bool ans = 1;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
        //cout << mp[ str[0] ] << " " << mp2[ str[1] ] << nl;
        if(!mp[ str[0] ] || !mp2[ str[1] ]) ans = 0;
    }
    if(ans && s.size() == n) cout << "Yes" << nl;
    else cout << "No" << nl;

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

