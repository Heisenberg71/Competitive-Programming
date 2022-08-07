#include <bits/stdc++.h>
#define ll long long
#define base 31
#define base2 101
#define mod 1000000007
#define mod2 1000000009
#define nl '\n'
#define LIM 5005
using namespace std;

ll k;
ll dp[LIM], prefHash[LIM], prefHash2[LIM], basePower[LIM], basePower2[LIM];
string str, patt;
char temp[1000006];

unordered_set <ll> uos, uos2;

void preCal()
{
    prefHash[0] = str[0] - 'a' + 1;
    basePower[0] = 1;

    prefHash2[0] = str[0] - 'a' + 1;
    basePower2[0] = 1;

    for(int i = 1; i < str.size(); i++){
        basePower[i] = (basePower[i - 1]*base) %mod;
        prefHash[i] = (prefHash[i - 1]*base + str[i] - 'a' + 1) %mod;

        basePower2[i] = (basePower2[i - 1]*base2) %mod2;
        prefHash2[i] = (prefHash2[i - 1]*base2 + str[i] - 'a' + 1) %mod2;
    }
}

ll evaluateHash(int L, int R)
{
    if(L == 0) return prefHash[R];
    return (prefHash[R] - (prefHash[L - 1]*basePower[R - L + 1]) %mod + mod) %mod;
}

ll evaluateHash2(int L, int R)
{
    if(L == 0) return prefHash2[R];
    return (prefHash2[R] - (prefHash2[L - 1]*basePower2[R - L + 1]) %mod2 + mod2) %mod2;
}

ll fun()
{
    dp[ str.size() ] = 1;
    for(int i = str.size() - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(uos.find(evaluateHash(j, i)) != uos.end() && uos2.find(evaluateHash2(j, i)) != uos2.end()){
                dp[j] = (dp[j] + dp[i + 1]) %mod;
            }
        }
    }

    return dp[0];
}

int main()
{
    scanf("%s %lld", temp, &k);
    str = temp;
    for(int i = 0; i < k; i++){
        scanf(" %s", temp);
        patt = temp;

        //cout << patt << nl;

        ll val = 0, val2 = 0;
        for(int j = 0; j < patt.size(); j++){
            val = (val*base + patt[j] - 'a' + 1) %mod;
            val2 = (val2*base2  + patt[j] - 'a' + 1) %mod2;
        }

        uos.insert(val);
        uos2.insert(val2);
    }

    preCal();

    printf("%lld\n", fun());

    return 0;
}
