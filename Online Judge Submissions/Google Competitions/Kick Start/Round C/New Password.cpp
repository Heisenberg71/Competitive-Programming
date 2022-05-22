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



int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    int t, n, cas = 1;
    string str;
    cin >> t;
    while(t--){
        cin >> n >> str;
        bool up = 0, lo = 0, sp = 0, dig = 0;
        for(int i = 0; i < n; i++){
            if('A' <= str[i] && str[i] <= 'Z') up = 1;
            if('a' <= str[i] && str[i] <= 'z') lo = 1;
            if('0' <= str[i] && str[i] <= '9') dig = 1;
            if(str[i] == '#' || str[i] == '@' || str[i] == '*' || str[i] == '&') sp = 1;
        }
        if(up == 0) str += 'A';
        if(lo == 0) str += 'a';
        if(sp == 0) str += '&';
        if(dig == 0) str += '1';

        while(str.size() < 7) str += 'a';

        printf("Case #%d: ", cas++);
        cout << str << nl;
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
*/
