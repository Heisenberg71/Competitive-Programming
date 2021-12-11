#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, a, b, c;
    while(cin >> t){
        if(t == 0) break;
        ll vol = 0, hei = 0;
        while(t--){
            cin >> a >> b >> c;
            if(hei <= c){
                if(hei == c) vol = max(vol, a*b*c);
                else vol = a*b*c;
                hei = c;
            }
        }
        cout << vol << endl;
    }
    return 0;
}
