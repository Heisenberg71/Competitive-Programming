#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define nl "\n"
using namespace std;

ll arr[LIM], brr[LIM];
ll msb[21], bits[21], bitTable[21][21]; /// bitTable[ i'th bit is the MSB ][ j'th bit is on ]

int main()
{
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        ll sumArr = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sumArr += arr[i];
        }
        for(int i = 0; i < n; i++)
            cin >> brr[i];

        for(int i = 0; i < n; i++){
            int MSB = 20, temp = arr[i];
            for(int j = 0; arr[i]; j++){
                if(arr[i]%2){
                    bits[j]++;
                    MSB = j;
                }
                arr[i] /= 2;
            }
            if(MSB != 20) msb[MSB]++;

            for(int j = 0; j < 20; j++){
                if(temp&(1 << j)) bitTable[MSB][j]++;
            }
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(brr[i] == 0){
                ans += sumArr;
                continue;
            }
            for(int j = 0; j < 20; j++){
                int k, temp = brr[i];
                for(int j = 0; temp; j++){
                    if(temp%2) k = j;
                    temp /= 2;
                }

                if(brr[i]&(1 << j)){
                    ans += (1 << j)*bitTable[k][j];
                    ans += (1 << j)*(n - msb[k] - (bits[j] - bitTable[k][j]));
                }
                else{
                    ans += (1 << j)*(bits[j] - bitTable[k][j]);
                }
            }
        }

        cout << ans << nl;

        memset(msb, 0, sizeof msb);
        memset(bits, 0, sizeof bits);
        memset(bitTable, 0, sizeof bitTable);
    }

    return 0;
}
