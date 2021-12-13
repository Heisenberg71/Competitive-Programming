#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, cas = 1, k, i, x;
    cin >> t;
    while(t--){
        cin >> k;
        int pre, ans = 0;
        for(i = 0; i < 2*k; i++){
            cin >> x;
            if(i%2) ans ^= (x-pre-1);
            pre = x;
        }
        printf("Case %d: ", cas++);
        if(ans) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}
