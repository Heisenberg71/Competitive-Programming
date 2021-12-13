#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t, cas = 1, n, black[105], white[105], i;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> white[i];
        for(i = 0; i < n; i++)
            cin >> black[i];
        int ans = 0;
        for(i = 0; i < n; i++)
            ans ^= (black[i] - white[i] - 1);
        printf("Case %d: ", cas++);
        if(ans) cout << "white wins" << endl;
        else cout << "black wins" << endl;
    }
    return 0;
}
