#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define mod 1000000007
#define mod2 1000000009
#define base 31
#define base2 101
#define nl '\n'
using namespace std;

int n;
string str, str2;
ll prefHash[2][LIM], prefHash2[2][LIM], basePower[LIM], basePower2[LIM];

void preCal()
{
    prefHash[0][0] = str[0] - 'A';
    prefHash[1][0] = str2[0] - 'A';
    basePower[0] = 1;

    prefHash2[0][0] = str[0] - 'A';
    prefHash2[1][0] = str2[0] - 'A';
    basePower2[0] = 1;

    for(int i = 1; i <= n; i++){
        basePower[i] = (basePower[i - 1]*base) %mod;
        prefHash[0][i] = ((prefHash[0][i - 1]*base) %mod + str[i] - 'A') %mod;
        prefHash[1][i] = ((prefHash[1][i - 1]*base) %mod + str2[i] - 'A') %mod;

        basePower2[i] = (basePower2[i - 1]*base2) %mod2;
        prefHash2[0][i] = ((prefHash2[0][i - 1]*base2) %mod2 + str[i] - 'A') %mod2;
        prefHash2[1][i] = ((prefHash2[1][i - 1]*base2) %mod2 + str2[i] - 'A') %mod2;
    }
}

ll evaluateHash(int idx, int L, int R)
{
    if(L == 0) return prefHash[idx][R];
    return ((prefHash[idx][R] - (prefHash[idx][L - 1]*basePower[R - L + 1]) %mod) %mod + mod) %mod;
}

ll evaluateHash2(int idx, int L, int R)
{
    if(L == 0) return prefHash2[idx][R];
    return ((prefHash2[idx][R] - (prefHash2[idx][L - 1]*basePower2[R - L + 1]) %mod2) %mod2 + mod2) %mod2;
}

/// use evaluateHash(0/1, L, R) to get hash value from L to R for base and mod of prefix string 0/1
/// use evaluateHash2(0,1, L, R) to get hash value from L to R for base2 and mod2 of prefix string 0/1
