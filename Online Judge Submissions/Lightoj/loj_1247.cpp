#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, cas = 1, i, j, x, m, n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        int ans = 0;
        for(i = 0; i < m; i++){
            int sum = 0;
            for(j = 0; j < n; j++){
                cin >> x;
                sum += x;
            }
            ans ^= sum;
        }
        printf("Case %d: ", cas++);
        if(ans) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}
