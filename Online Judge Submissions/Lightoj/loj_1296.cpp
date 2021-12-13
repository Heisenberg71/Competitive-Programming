#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n, g[1005], cnt[1005];

//int MEX()
//{
//    int i;
//    for(i = 0; i < 1005; i++)
//        if(!cnt[i]) break;
//    return i;
//}
//
//void grandy()
//{
//    int i, j;
//    for(i = 0; i < 1005; i++){
//        memset(cnt, 0, sizeof cnt);
//        //cout << i-1 << " " << i << endl;
//        for(j = i-1; 2*j >= i; j--)
//            cnt[g[j]] = 1;
//        g[i] = MEX();
//    }
//}

int grandy(int n)
{
    if(n%2 == 0) return n/2;
    return grandy(n/2);
}

int main()
{
//    for(int i = 0; i < 100; i++)
//        cout << i << " " << grandy(i) << endl;

    int t, cas = 1, i, x;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(i = 0; i < n; i++){
            cin >> x;
            ans ^= grandy(x);
        }
        printf("Case %d: ", cas++);
        if(ans) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}
