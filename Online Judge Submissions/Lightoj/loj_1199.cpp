#include <bits/stdc++.h>
#define ll long long
#define LIM 10005
using namespace std;

int g[LIM], cnt[LIM + LIM];

int grandy()
{
    int i, j;

    for(i = 3; i < LIM; i++){
        memset(cnt, 0, sizeof cnt);
        for(j = 1; j < i; j++)
            cnt[(g[j] ^ g[i-j])] = (j != i-j);
        for(j = 0; j <= i+1; j++)
            if(!cnt[j]) break;
        g[i] ^= j;
    }

}

int main()
{
    grandy();

    int t, n, cas = 1, x;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        while(n--){
            cin >> x;
            ans ^= g[x];
        }
        printf("Case %d: ", cas++);
        if(ans) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}

