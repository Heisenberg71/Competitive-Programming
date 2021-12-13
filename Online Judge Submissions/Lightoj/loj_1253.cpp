#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t, cas = 1, n, i, x;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0, f = 0;
        for(i = 0; i < n; i++){
            cin >> x;
            if(x > 1) f = 1;
            ans ^= x;
        }
        printf("Case %d: ", cas++);
        if(f){
            if(ans) cout << "Alice" << endl;
            else cout << "Bob" << endl;
        }
        else{
            if(n%2) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }
    return 0;
}
