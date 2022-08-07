#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define LIM 1000006
using namespace std;
 
ll k;
ll prefHash[2][LIM], basePower[2][LIM];
ll mod[2] = {1000000007, 1000000009};
ll base[2] = {31, 101};
string str, patt;
char temp[LIM];
 
void preCal()
{
    prefHash[0][0] = prefHash[1][0] = str[0] - 'a' + 1;
    basePower[0][0] = basePower[1][0] = 1;
 
   for(int j = 0; j < 2; j++){
        for(int i = 1; i < str.size(); i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
            prefHash[j][i] = (prefHash[j][i - 1]*base[j] + str[i] - 'a' + 1) %mod[j];
            //cout << prefHash[j][i] << nl;
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
    scanf("%s", temp);
    patt = temp;
 
    preCal();
 
    ll val = 0, val2 = 0;
    for(int i = 0; i < patt.size(); i++){
        val = (val*base[0] + patt[i] - 'a' + 1) %mod[0];
        val2 = (val2*base[1] + patt[i] - 'a' + 1) %mod[1];
    }
 
    int ans = 0;
    for(int i = 0, j = patt.size() - 1; j < str.size(); i++, j++){
        //cout << evaluateHash(0, i, j) << " " << evaluateHash(1, i, j) << nl;
        if(evaluateHash(0, i, j) == val && evaluateHash(1, i, j) == val2)
            ans++;
    }
 
    printf("%d\n", ans);
 
    return 0;
}
