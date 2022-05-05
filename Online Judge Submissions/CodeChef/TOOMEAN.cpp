#include <bits/stdc++.h>
#define ll long long
#define LIM 300005
#define nl "\n"
using namespace std;

double arr[LIM];

int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        double tot = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            tot += arr[i];
        }
        sort(arr, arr + n);
        double ans = 0.0, currSum = 0.0;
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            ans = max(ans, (currSum/(i + 1) + (tot - currSum))/(n - i));
        }
        cout << fixed << setprecision(10) << ans << nl;
    }

    return 0;
}
