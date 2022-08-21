#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define LIM 1000006
using namespace std;

ll prefHash[2][LIM], prefHash2[2][LIM], basePower[2][LIM];
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

    string str2 = str;
    reverse(str2.begin(), str2.end());

    prefHash2[0][0] = prefHash2[1][0] = str2[0] - 'a' + 1;
    basePower[0][0] = basePower[1][0] = 1;

   for(int j = 0; j < 2; j++){
        for(int i = 1; i < str2.size(); i++){
            basePower[j][i] = (basePower[j][i - 1]*base[j]) %mod[j];
            prefHash2[j][i] = (prefHash2[j][i - 1]*base[j] + str2[i] - 'a' + 1) %mod[j];
        }
    }
}

ll getHash(int idx, int L, int R)
{
    if(L == 0) return prefHash[idx][R];
    return (prefHash[idx][R] - (prefHash[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

ll getHash2(int idx, int L, int R)
{
    if(L == 0) return prefHash2[idx][R];
    return (prefHash2[idx][R] - (prefHash2[idx][L - 1]*basePower[idx][R - L + 1]) %mod[idx] + mod[idx]) %mod[idx];
}

int main()
{
    int t, cas = 1, n;
    cin >> t;
    while(t--){
        cin >> n >> str;
        cout << "Case #" << cas++ << ": ";
        preCal();

        int sz = str.size();
        bool found = 0;
        for(int i = 0; i < sz - 1; i++){
//         cout << 0 << " " << i << " " << sz - 1 - i << " " << sz - 1 << endl;
//        cout << i + 1 << " " << sz - 1 << " " << 0 << " " << sz - i - 2 << endl;
            if(getHash(0, 0, i) == getHash2(0, sz - 1 - i, sz - 1) &&
             getHash(1, 0, i) == getHash2(1, sz - 1 - i, sz - 1) &&
             getHash(0, i + 1, sz - 1) == getHash2(0, 0, sz - i - 2) &&
             getHash(1, i + 1, sz - 1) == getHash2(1, 0, sz - i - 2)){
                for(int j = 0; j <= i; j++)
                    cout << str[j];
                cout << nl;
                found = 1;
                break;
            }
        }

        if(!found) cout << str << nl;
    }

    return 0;
}
