#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf (1<<30)
#define LIM 300005
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t, n, grid[15][15], i, j, k, l, cas = 1, cnt[15];
    cin >> t;
    while(t--){
        cin >> n;
        ll coun = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> grid[i][j];
        for(i = 0; i < n; i++){
            memset(cnt,0,sizeof cnt);
            for(j = 0; j < min(n,10LL); j++){
                cnt[grid[i][j]]++;
            }
            for(j = 1; j <= 10; j++)
                if(cnt[j] != 1) break;
            if(j == 11) coun++;
        }
        for(i = 0; i < n; i++){
            memset(cnt,0,sizeof cnt);
            for(j = 0; j < min(n,10LL); j++){
                cnt[grid[j][i]]++;
            }
            for(j = 1; j <= 10; j++)
                if(cnt[j] != 1) break;
            if(j == 11) coun++;
        }
        //cout << coun << endl;
        for(i = 0; i < n-1; i++){
            for(j = 0; j < n-4; j++){
                memset(cnt,0,sizeof cnt);
                for(k = i; k < 2+i; k++){
                    for(l = j; l < 5+j; l++){
                        cnt[grid[k][l]]++;
                    }
                }
                for(k = 1; k <= 10; k++){
                    if(cnt[k] != 1) break;
                }
                if(k == 11) coun++;
            }
        }
        for(i = 0; i < n-1; i++){
            for(j = 0; j < n-4; j++){
                memset(cnt,0,sizeof cnt);
                for(k = i; k < 2+i; k++){
                    for(l = j; l < 5+j; l++){
                        cnt[grid[l][k]]++;
                    }
                }
                for(k = 1; k <= 10; k++){
                    if(cnt[k] != 1) break;
                }
                if(k == 11) coun++;
            }
        }
        printf("Case %lld: %lld\n", cas++, coun);
    }



    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/


