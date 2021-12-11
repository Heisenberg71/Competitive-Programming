#include <bits/stdc++.h>
#define ll long long
#define LIM 1005
using namespace std;

int dp[LIM];
string s;

int toggle(int mark, int pos) { return (mark ^ (1 << pos)); }

int main()
{
    int i, j, t, cas = 1;

    cin >> t;
    while(t--){
        cin >> s;
        for(i = 0; i < s.size(); i++)
            dp[i + 1] = toggle(dp[i], s[i] - 'a');

        int cnt = 0;
        for(i = 1; i <= s.size(); i++){
            for(j = 1; j <= i; j++){
                //cout << dp[i] << " " << dp[j] << " " << (dp[i] & dp[j]) << endl;
                if(__builtin_popcount((dp[i] ^ dp[j - 1])) <= 1) cnt++;
            }
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
