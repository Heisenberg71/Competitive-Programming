#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
using namespace std;
int main()
{
    int t, cas = 1;
    double r1, r2, r3, area, a, b, c, A, B, C, s;
    cin >> t;
    while(t--){
        cin >> r1 >> r2 >> r3;
        a = r1+r2, b = r1+r3, c = r3+r2;
        s = (a+b+c)/2;
        area = s * (s-a) * (s-b) * (s-c);
        area = sqrt(area);
        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*a*c));
        C = acos((a*a+b*b-c*c)/(2*a*b));
        area -= (0.5*r1*r1*C + 0.5*r2*r2*B + 0.5*r3*r3*A);
        printf("Case %d: %0.10lf\n", cas++, area+eps);
    }
    return 0;
}
