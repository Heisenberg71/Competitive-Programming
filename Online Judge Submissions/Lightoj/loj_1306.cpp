#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll tem;
    if(a == 0 and b == 0){
        if(c == 0) return (abs(minx-maxx)+1)*(abs(miny-maxy)+1);
        else return 0;
    }
    else if(a == 0){
        tem = c/b;
        if(c%b == 0 and tem >= miny and tem <= by) return abs(minx-maxx)+1;
        else return 0;
    }
    else if(b == 0){
        tem = c/a;
        if(c%a == 0 and tem >= minx and tem <= maxx) return abs(miny-maxy)+1;
        else return 0;
    }
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main()
{
    ll t, ax, ay, bx, by, cas = 1, a, b, c, d, tem;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >>  ax >> bx >> ay >> by;
        if(a == 0 and b == 0){
            if(c == 0) printf("Case %lld: %lld\n", cas++, (abs(ax-bx)+1)*(abs(ay-by)+1));
            else printf("Case %lld: 0\n", cas++);
        }
        else if(a == 0){
            tem = (-1*c)/b;
            if((-1*c)%b == 0 and tem >= ay and tem <= by) printf("Case %lld: %lld\n", cas++, abs(ax-bx)+1);
            else printf("Case %lld: 0\n", cas++);
        }
        else if(b == 0){
            tem = (-1*c)/a;
            if((-1*c)%a == 0 and tem >= ax and tem <= bx) printf("Case %lld: %lld\n", cas++, abs(ay-by)+1);
            else printf("Case %lld: 0\n", cas++);
        }
        else printf("Case %lld: %lld\n", cas++, find_all_solutions(a,b,-1*c,ax,bx,ay,by));
    }
    return 0;
}
