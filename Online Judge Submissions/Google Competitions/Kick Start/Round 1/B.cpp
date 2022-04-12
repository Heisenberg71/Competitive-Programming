#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
int main()
{
    int t, cas = 1;
    string str;

    cin >> t;
    while(t--){
        cin >> str;

        int sum = 0;
        for(int i = 0; i < str.size(); i++)
            sum += str[i] - '0';

        char dig = (9 - sum%9)%9 + '0';

        printf("Case #%d: ", cas++);

        if(dig == '0'){
            cout << str[0];
            cout << dig;
            for(int i = 1; i < str.size(); i++)
                cout << str[i];
            cout << nl;
        }
        else{
            int pos = str.size();
            for(int i = 0; i < str.size(); i++){
                if(dig < str[i]){
                    pos = i;
                    break;
                }
            }
            for(int i = 0; i < pos; i++)
                cout << str[i];
            cout << dig;
            for(int i = pos; i < str.size(); i++)
                cout << str[i];
            cout << nl;
        }
    }

    return 0;
}
