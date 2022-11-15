#include <bits/stdc++.h>
#define ll long long
#define inf 2000000000000015
#define LIM 400005
#define nl '\n'
using namespace std;

int arr[LIM];

int main()
{
    int n, m;

    cin >> n >> m;
    ll tot = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        tot += arr[i];
        arr[i + n] = arr[i];
    }

    ll sum = arr[0], ans = inf;
    for(int i = 1; i < n + n; i++){
        if(arr[i - 1] == arr[i] || (arr[i - 1] + 1) %m == arr[i]%m) sum += arr[i];
        else sum = arr[i];
        ans = max(0LL, min(ans, tot - sum));
    }

    cout << ans << nl;

    return 0;
}
