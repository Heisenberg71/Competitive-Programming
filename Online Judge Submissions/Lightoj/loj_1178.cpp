#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
int main()
{
    int t, cas = 1;
    double a, b, c, d, area;
    cin >> t;
    while(t--){
        cin >> a >> c >> b >> d;
        double A, B, C, D, h;
        A = - a + b + c + d;
        B =   a - b + c + d;
        C =   a - b + c - d;
        D =   a - b - c + d;
        double x = A*B*C*D;
       //cout << "x: " << x << endl;
        h = sqrt(x) / (2* abs(B-A));
        //cout << h << endl;
        area = h * (a + b);
        printf("Case %d: %0.10lf\n", cas++, area + eps);
    }
    return 0;
}
