#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, cas = 1, n;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int ball = 0;
            for(int j = 0; j < 6; j++){
                int x;
                cin >> x;
                ball += x;
            }
            if(!ball) ans++;
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
