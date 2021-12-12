#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define LIM 1000006
#define base 31
using namespace std;

char s[LIM];
unordered_map <ull, ll> mp;
ull pw[LIM];

void precal()
{
    ll i;
    pw[0] = 1;
    for(i = 1; i < LIM; i++)
        pw[i] = base * pw[i - 1];
}

int main()
{
    precal();

    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", s);

        ull strhash = 0;
        ll len = strlen(s);
        for(int j = 0; j < len; j++){
            strhash += pw[j] * (s[j] - 'a' + 1);
        }

        for(int j = 0; j < len; j++){
            for(int alp = 1; alp <= 26; alp++){
                if(s[j] - 'a' + 1 != alp){
                    ull hashval = strhash;
                    hashval -= pw[j] * (s[j] - 'a' + 1);
                    hashval += pw[j] * alp;
                    if(mp.count(hashval) > 0){
                        ans += mp[hashval];
                    }
                }
            }
        }

        mp[strhash]++;
    }

    printf("%lld\n", ans);

    return 0;
}
