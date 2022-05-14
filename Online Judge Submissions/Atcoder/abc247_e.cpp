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

int arr[LIM];
int minTable[LIM][22], maxTable[LIM][22], logArray[LIM];

void construct(int n)
{
    logArray[1] = 0;
    for(int i = 2; i <= n; i++)
        logArray[i] = 1 + logArray[i/2];

    for(int i = 0; i < n; i++){
        minTable[i][0] = arr[i];
        maxTable[i][0] = arr[i];
    }

    for(int j = 1; j <= logArray[n] + 1; j++){
        for(int i = 0; i + (1 << (j - 1)) < n; i++){
            minTable[i][j] = min(minTable[i][j - 1], minTable[i + (1 << (j - 1)) ][j - 1]);
            maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1)) ][j - 1]);
        }
    }
}

int minQuery(int L, int R)
{
    int len = R - L + 1;
    int lg = logArray[len];
    return min(minTable[L][lg], minTable[R - (1 << lg) + 1][lg]);
}

int maxQuery(int L, int R)
{
    int len = R - L + 1;
    int lg = logArray[len];
    return max(maxTable[L][lg], maxTable[R - (1 << lg) + 1][lg]);
}

int bs(int pos, int n, int x, int y)
{
    int lo = pos, hi = n - 1, md, ans = pos - 1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        int rangeMin = minQuery(pos, md);
        int rangeMax = maxQuery(pos, md);
        if(x == rangeMax && rangeMin == y){
            ans = md;
            lo = md + 1;
        }
        else if((x >= rangeMax && y < rangeMin) || (x > rangeMax && y <= rangeMin)){
            lo = md + 1;
        }
        else{
            hi = md - 1;
        }
    }
    return ans;
}

int bs2(int pos, int n, int x, int y)
{
    int lo = pos, hi = n - 1, md, ans = pos;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        int rangeMin = minQuery(pos, md);
        int rangeMax = maxQuery(pos, md);
        if(x == rangeMax && rangeMin == y){
            ans = md;
            hi = md - 1;
        }
        else if((x >= rangeMax && y < rangeMin) || (x > rangeMax && y <= rangeMin)){
            lo = md + 1;
        }
        else{
            hi = md - 1;
        }
    }
    return ans;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    int n, x, y;

    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    construct(n);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += bs(i, n, x, y) - bs2(i, n, x, y) + 1;
    }

    cout << ans << nl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
