#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000000009
#define nl "\n"
using namespace std;

int arr[305], brr[305];

int main()
{
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(arr[i] != i){
                for(int j = 1; j <= n; j++)
                    brr[j] = arr[j];

                ll cnt = 0, cnt2 = inf;
                int j = i;
                while(brr[j] != j){
                    cnt += brr[j] + j;
                    swap(brr[j], brr[ brr[j] ]);
                }

                if(i != 1){
                    for(int j = 1; j <= n; j++)
                        brr[j] = arr[j];

                    cnt2 = 1 + i;
                    swap(brr[1], brr[i]);

                    j = 1;
                    while(brr[j] != j){
                        cnt2 += brr[j] + j;
                        swap(brr[j], brr[ brr[j] ]);
                    }
                }

                ans += min(cnt, cnt2);

                for(int j = 1; j <= n; j++)
                    arr[j] = brr[j];
            }
        }

        cout << ans << nl;
    }
    return 0;
}
