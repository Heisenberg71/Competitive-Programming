#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define LIM 1000006
using namespace std;

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

int main()
{
    scanf("%s", temp);
    str = temp;

    preCal();

    int sz = str.size();
    for(int len = 1; len <= sz; len++){
        ll hashVal = 0, hashVal2 = 0;
        for(int j = 0; j + len <= sz; j += len){
            hashVal = ((hashVal*basePower[0][len]) %mod[0] + prefHash[0][len - 1]) %mod[0];
            hashVal2 = ((hashVal2*basePower[1][len]) %mod[1] + prefHash[1][len - 1]) %mod[1];
        }
        int rem = sz%len;
        if(rem){
            hashVal = ((hashVal*basePower[0][rem]) %mod[0] + prefHash[0][rem - 1]) %mod[0];
            hashVal2 = ((hashVal2*basePower[1][rem]) %mod[1] + prefHash[1][rem - 1]) %mod[1];
        }

        if(hashVal == prefHash[0][sz - 1] && hashVal2 == prefHash[1][sz - 1]) printf("%d ", len);
    }
    printf("\n");

    return 0;
}
