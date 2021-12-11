#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s, t;
ll dp[3005][3005], grid[3005][3005];
ll eval(ll a, ll b)
{
    if(a == s.size() or b == t.size()) return 0;
    else return dp[a][b];
}
void f()
{
    ll i, j;
    for(i = s.size()-1; i >= 0; i--){
        for(j = t.size()-1; j >= 0; j--){
            ll a = -inf, b = -inf, c = -inf;
            if(s[i] == t[j]) a = 1+eval(i+1,j+1);
            else{
                b = eval(i,j+1);
                c = eval(i+1,j);
            }
            if(a >= b and a >= c) grid[i][j] = 1;
            else if(b >= a and b >= c) grid[i][j] = 2;
            else grid[i][j] = 3;
            dp[i][j] = max(a,max(b,c));
        }
    }
}
void g()
{
    string patt;
    ll i = 0, j = 0;
    while(dp[i][j] != 0){
        if(grid[i][j] == 1) patt += s[i], i = i+1, j = j+1;
        else if(grid[i][j] == 2) j = j+1;
        else i = i+1;
    }
    cout << patt << endl;
}
int main()
{
    ll i;
    cin >> s >> t;
    f();
    g();
    return 0;
}
