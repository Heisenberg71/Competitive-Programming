#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[405], val[405][405], cost[405][405];
ll f()
{
    ll i, j, k;

    memset(cost,127,sizeof(cost));
    for(i = 0; i < n; i++){
        val[i][i] = arr[i];
        cost[i][i] = 0;
    }

    for(i = 1; i < n; i++){
        for(j = 0; j < n-i; j++){
            //cout << j << i+j << endl;
            ll sum = 0;
            for(k = j; k < j+i; k++){
                cost[j][j+i] = min(cost[j][j+i],val[j][k]+val[k+1][j+i]+cost[j][k]+cost[k+1][j+i]);
                sum += arr[k];
            }
            val[j][j+i] = sum+arr[j+i];
        }
    }
//
//    for(i = 0; i < n; i++){
//        for(j = 0; j < n; j++){
//            if(cost[i][j] < 200) cout << cost[i][j] << " ";
//            else cout << 99 << " ";
//        }
//        cout << endl;
//    }
    return cost[0][n-1];
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << f() << endl;
    return 0;
}
