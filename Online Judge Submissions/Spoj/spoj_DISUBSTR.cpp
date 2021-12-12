#include <bits/stdc++.h>
#define ull unsigned long long
#define LIM 1005
#define base 257
using namespace std;

string sstr;
ull prefixHash[LIM], pw[LIM];

void precal()
{
    pw[0] = 1;
    for(int i = 1; i < LIM; i++)
        pw[i] = pw[i-1] * base;
}

void makeHash()
{
    prefixHash[0] = sstr[0];
    for(int i = 1; i <= sstr.size(); i++)
        prefixHash[i] = base * prefixHash[i-1] + sstr[i];
}

ull genHash(int L, int R)
{
    int i;
    if(!L) return prefixHash[R];
    return prefixHash[R] - prefixHash[L-1] * pw[R-L+1];
}

int main()
{
    precal();

    int t;
    char str[1005];
    cin >> t;
    while(t--){
        scanf("%s", &str);
        sstr = str;
        makeHash();
        ///abcdefg
        int ans = 0;
        for(int len = 1; len <= sstr.size(); len++){
            set <ull> s;
            for(int st = 0; st + len - 1 < sstr.size(); st++){
                s.insert(genHash(st, st+len-1));
            }
            ans += s.size();
        }

        cout << ans << endl;
    }
    return 0;
}
