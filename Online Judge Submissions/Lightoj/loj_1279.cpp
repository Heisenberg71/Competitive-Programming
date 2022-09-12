#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;

double L, W;

double f(double x)
{
    return (L - 2.0*x)*(W - 2.0*x)*x;
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}


int main()
{
    int t, cas = 1;

    cin >> t;
    while(t--){
        cin >> L >> W;
        //cout << ternary_search(0, min(L, W)) << nl;
        printf("Case %d: %0.10lf\n", cas++, ternary_search(0, min(L, W)/2.0));
    }

    return 0;
}
