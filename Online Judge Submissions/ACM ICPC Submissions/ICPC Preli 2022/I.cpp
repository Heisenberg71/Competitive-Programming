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

/**

Notes:


*/

double L, W;

double f(double x)
{
    double y, oti = L - x;
    y = sqrt(oti*oti - x*x);
//    cout << y << " " << x << nl;
//    cout << x << " " << oti << nl;
    return L - x + W - y + sqrt(x*x + y*y);
}

double ternary_search(double l, double r)
{
    while (r - l > eps) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        double f1 = f(m1);
        double f2 = f(m2);
        //cout << m1 << " " << m2 << nl;
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    while(1){
        int LL, WW;
        //scanf("%d %d", &LL, &WW);
        cin >> LL >> WW;
        if(LL == 0 && WW == 0) break;
        L = LL, W = WW;
        printf("%0.4lf\n", ternary_search(0, L/2.0));
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
