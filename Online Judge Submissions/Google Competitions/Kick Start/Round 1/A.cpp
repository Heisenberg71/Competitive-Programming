#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
int main()
{
    int t, cas = 1;
    string strI, strP;

    cin >> t;
    while(t--){
        cin >> strI >> strP;

        bool exist = 0;
        for(int i = 0, j = 0; i < strP.size() && j < strI.size(); i++){
            if(strP[i] == strI[j]) j++;
            if(strI.size() == j) exist = 1;
        }

        printf("Case #%d: ", cas++);
        if(exist) cout << strP.size() - strI.size() << nl;
        else cout << "IMPOSSIBLE" << nl;
    }

    return 0;
}
