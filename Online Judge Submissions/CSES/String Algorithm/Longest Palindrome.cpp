/*

O(nlogn) solution and verdicts TLE

*/

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define LIM 1000006
using namespace std;

ll prefHash[2][LIM], prefHash2[2][LIM], basePower[2][LIM], ansL, ansR;
ll mod[2] = {1000000007, 1000000009};
ll base[2] = {31, 101};
string str, str2;
char temp[LIM];

void preCal()
{
    prefHash[0][0] = prefHash[1][0] = str[0] - 'a' + 1;
    prefHash2[0][0] = prefHash2[1][0] = str2[0] - 'a' + 1;
    basePower[0][0] = basePower[1][0] = 1;

   for(int j = 0; j < 2; j++){
        for(int i = 1; i < str.size(); i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
            prefHash[j][i] = (prefHash[j][i - 1]*base[j] + str[i] - 'a' + 1) %mod[j];
            prefHash2[j][i] = (prefHash2[j][i - 1]*base[j] + str2[i] - 'a' + 1) %mod[j];
        }
    }
}

ll evaluateHash(int idx, int L, int R)
{
    if(L == 0) return prefHash[idx][R];
    return (prefHash[idx][R] - (prefHash[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

ll evaluateHash2(int idx, int L, int R)
{
    if(L == 0) return prefHash2[idx][R];
    return (prefHash2[idx][R] - (prefHash2[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

bool fun(int len)
{
    int sz = str.size();

    bool found = 0;
    for(int L = 0, R = len - 1, L2 = sz - len, R2 = sz - 1; R < sz; L++, R++, L2--, R2--){
        if(evaluateHash(0, L, R) == evaluateHash2(0, L2, R2) && evaluateHash(1, L, R) == evaluateHash2(1, L2, R2)){
            ansL = L, ansR = R;
            found = 1;
        }
    }

    return found;
}

void bs()
{
    int lo = 1, hi = str.size(), md;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        //cout << md << nl;
        if(fun(md) || fun(md + 1)) lo = md + 1;
        else hi = md - 1;
    }
}

int main()
{
    scanf("%s", temp);
    str = temp;
    str2 = temp;
    reverse(str2.begin(), str2.end());

    preCal();

//    cout << evaluateHash(0, 2, 4) << " " << evaluateHash2(0, 2, 4) << nl;
//    cout << evaluateHash(1, 2, 4) << " " << evaluateHash2(1, 2, 4) << nl;

    bs();
    for(int i = ansL; i <= ansR; i++)
        cout << str[i];
    cout << nl;

    return 0;
}
