#include <bits/stdc++.h>
#define ll long long
#define esp 1e-9
using namespace std;
double arr[1000005];
int main()
{
    ll t, n, base, i, cas = 1;
    arr[1] = log10(1);
    for(i = 2; i <= 1000000; i++)
        arr[i] = arr[i-1] + log10(i);
    cin >> t;
    while(t--){
        cin >> n >> base;
        printf("Case %lld: ", cas++);
        if(n == 0)
            cout << 1 << endl;
        else{
            ll tem = arr[n]/log10(base) + 1 + esp;
            cout << tem  << endl;
        }
    }
    return 0;
}
