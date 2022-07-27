#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define LIM 2505
#define inf 1000000009
using namespace std;

int n, m;
int str[LIM], keyboard[LIM], dp[LIM][LIM];
vector <int> v[LIM];

int Left(int keyboardPos, int value)
{
    int lo = 0, hi = v[value].size() - 1, md, ans = -1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(v[value][md] <= keyboardPos){
            ans = v[value][md];
            lo = md + 1;
        }
        else{
            hi = md - 1;
        }
    }

    if(ans != -1) return abs(ans - keyboardPos);
    return -1;
}

int Right(int keyboardPos, int value)
{
    int lo = 0, hi = v[value].size() - 1, md, ans = -1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(v[value][md] >= keyboardPos){
            ans = v[value][md];
            hi = md - 1;
        }
        else lo = md + 1;
    }

    if(ans != -1) return abs(ans - keyboardPos);
    return -1;
}

int fun(int strPos, int keyboardPos)
{
    if(strPos == n) return 0;
    if(dp[strPos][keyboardPos] != -1) return dp[strPos][keyboardPos];

    int a = inf, b = inf;
    if(Left(keyboardPos, str[ strPos ]) != -1) a = Left(keyboardPos, str[ strPos ]) + fun(strPos + 1, keyboardPos - Left(keyboardPos, str[ strPos ]));
    if(Right(keyboardPos, str[ strPos ]) != -1) b = Right(keyboardPos, str[ strPos ]) + fun(strPos + 1, keyboardPos + Right(keyboardPos, str[ strPos ]));

    return dp[strPos][keyboardPos] = min(a, b);
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> str[i];
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> keyboard[i];
            v[ keyboard[i] ].pb(i);
        }

        memset(dp, -1, sizeof dp);
        int ans = inf;
        for(int i = 0; i < m; i++)
            ans = min(ans, fun(0, i));
        cout << "Case #" << cas++ << ": " << ans << nl;

//        cout << Left(5, 4) << nl;
//        cout << Right(5, 4) << nl;
//        cout <<  << nl;
//        cout <<  << nl;

        for(int i = 0; i <= LIM; i++)
            v[i].clear();
    }

    return 0;
}
