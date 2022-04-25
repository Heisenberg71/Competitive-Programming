#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

int n, bad5[(1 << 5)], bad6[(1 << 6)];
string str;

void preCal()
{
    for(int i = 0; i < (1 << 5); i++){
        string s, t;
        for(int j = 0; j < 5; j++){
            if(i&(1 << j)) s += '1';
            else s += '0';
        }
        t = s;
        reverse(s.begin(), s.end());
        bad5[i] = (s == t);
    }

    for(int i = 0; i < (1 << 6); i++){
        string s, t;
        for(int j = 0; j < 6; j++){
            if(i&(1 << j)) s += '1';
            else s += '0';
        }
        t = s;
        reverse(s.begin(), s.end());
        bad6[i] = (s == t);
    }

}

int fun(int pos, int k5, int k6)
{
    if(pos >= 5 && bad5[k5]) return 0;
    if(pos >= 6 && bad6[k6]) return 0;
    if(pos == n) return 1;

    if(str[pos] == '0' || str[pos] == '?'){
        int nk5 = k5*2;
        nk5 %= (1 << 5);
        int nk6 = k6*2;
        nk6 %= (1 << 6);
        if(fun(pos + 1, nk5, nk6)) return 1;
    }
    if(str[pos] == '1' || str[pos] == '?'){
        int nk5 = k5*2 + 1;
        nk5 %= (1 << 5);
        int nk6 = k6*2 + 1;
        nk6 %= (1 << 6);
        if(fun(pos + 1, nk5, nk6)) return 1;
    }

    return 0;
}

int main()
{
    preCal();

    int t, cas = 1;

    cin >> t;
    while(t--){
        cin >> n >> str;

        printf("Case #%d: ", cas++);
        if(fun(0, 0, 0)) cout << "POSSIBLE" << nl;
        else cout << "IMPOSSIBLE" << nl;
    }

    return 0;
}
