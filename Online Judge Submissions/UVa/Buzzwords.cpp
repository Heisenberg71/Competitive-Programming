#include <bits/stdc++.h>
#define ll long long
#define LIM 1003
#define nl '\n'
using namespace std;

ll prefHash[2][LIM], basePower[2][LIM];
ll mod[] = {1000000007, 1000000009}, base[] = {31, 101};
vector <ll> v, v2;

ll getHash(int typ, int L, int R)
{
    if(!L) return prefHash[typ][R];
    return (prefHash[typ][R] - (prefHash[typ][L - 1]*basePower[typ][R - L + 1]) %mod[typ] + mod[typ]) %mod[typ];
}

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;
    bool f = 0;
    while(getline(cin, str)){
        if(f) cout << nl; f = 1;
        string s;
        for(int i = 0; i < str.size(); i++)
            if(str[i] != ' ') s += str[i];

        prefHash[0][0] = prefHash[1][0] = s[0] - 'A';
        basePower[0][0] = basePower[1][0] = 1;
        for(int i = 1; i < s.size(); i++){
            basePower[0][i] = (basePower[0][i - 1]*base[0]) %mod[0];
            basePower[1][i] = (basePower[1][i - 1]*base[1]) %mod[1];
            prefHash[0][i] = ((prefHash[0][i - 1]*base[0]) %mod[0] + s[i] - 'A') %mod[0];
            prefHash[1][i] = ((prefHash[1][i - 1]*base[1]) %mod[1] + s[i] - 'A') %mod[1];
        }

        //cout << s.size() << nl;
        for(int len = 1; len <= s.size(); len++){
            unordered_map<ll, ll> ump, ump2;
            ll mx = 0;
            for(int j = 0, k = len - 1; k < s.size(); j++, k++){
                ll x = getHash(0, j, k), y = getHash(1, j, k);
                ump[x]++, ump2[y]++;
                if(ump[x] == ump2[y]) mx = max(mx, ump[x]);
            }
            if(mx > 1) cout << mx << nl;
            else break;
        }
    }

    return 0;
}
