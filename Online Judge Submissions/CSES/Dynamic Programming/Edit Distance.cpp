#include <bits/stdc++.h>
#define ll long long
#define LIM 5005
#define nl "\n"
using namespace std;

string str, str2;
int dp[LIM][LIM];

int f(int idx, int idx2)
{
    if(idx2 == (int)str2.size()) return (int)str.size() - idx;
    if(idx == (int)str.size()) return (int)str2.size() - idx2;
    if(dp[idx][idx2] != -1) return dp[idx][idx2];

    if(str[idx] == str2[idx2]){
        return dp[idx][idx2] = f(idx + 1, idx2 + 1);
    }
    else{
        int a, b, c;
        a = 1 + f(idx + 1, idx2 + 1); /// replace
        b = 1 + f(idx + 1, idx2); /// remove
        c = 1 + f(idx, idx2 + 1); /// add
        return dp[idx][idx2] = min(a, min(b, c));
    }
}

int main()
{
    cin >> str >> str2;

    memset(dp, -1, sizeof dp);
    int mn = f(0, 0);

    cout << mn << nl;

    return 0;
}
