#include <bits/stdc++.h>
#define ll long long
using namespace std;
int factorialDigitExtended ( int n, int base ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}

int main()
{
    ll t, n, i;
}
