#define LIM 1000006

ll prefHash[2][LIM], basePower[2][LIM];
ll mod[2] = {1000000007, 1000000009};
ll base[2] = {31, 101};
string str;
char temp[LIM];

void preCal()
{
    prefHash[0][0] = prefHash[1][0] = str[0] - 'a' + 1;
    basePower[0][0] = basePower[1][0] = 1;

   for(int j = 0; j < 2; j++){
        for(int i = 1; i < str.size(); i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
            prefHash[j][i] = (prefHash[j][i - 1]*base[j] + str[i] - 'a' + 1) %mod[j];
        }
    }
}

ll evaluateHash(int idx, int L, int R)
{
    if(L == 0) return prefHash[idx][R];
    return (prefHash[idx][R] - (prefHash[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}
