#define ll long long
#define LIM 1000006

ll prefHash[2][LIM], prefHashRev[2][LIM], basePower[2][LIM];
ll mod[2] = {1000000007, 1000000009};
ll base[2] = {31, 101};
string str, revStr;
char temp[LIM];

void preCal()
{
    prefHash[0][0] = prefHash[1][0] = str[0] - 'a' + 1;
    prefHashRev[0][0] = prefHashRev[1][0] = revStr[0] - 'a' + 1;
    basePower[0][0] = basePower[1][0] = 1;

   for(int j = 0; j < 2; j++){
        for(int i = 1; i < str.size(); i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
            prefHash[j][i] = (prefHash[j][i - 1]*base[j] + str[i] - 'a' + 1) %mod[j];
            prefHashRev[j][i] = (prefHashRev[j][i - 1]*base[j] + revStr[i] - 'a' + 1) %mod[j];
        }
    }
}

ll getHash(int idx, int L, int R)
{
    if(L == 0) return prefHash[idx][R];
    return (prefHash[idx][R] - (prefHash[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

ll getHashRev(int idx, int L, int R)
{
    if(L == 0) return prefHashRev[idx][R];
    return (prefHashRev[idx][R] - (prefHashRev[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

bool isPalindrome(int L, int R)
{
    int sz = str.size();
    if(getHash(0, L, R) == getHashRev(0, sz - R - 1 , sz - L - 1) &&
       getHash(1, L, R) == getHashRev(1, sz - R - 1, sz - L - 1)) return 1;
    return 0;
}

/// preCal() -> CALL FROM MAIN
/// isPalindrome(start, end) -> CALL FROM MAIN
