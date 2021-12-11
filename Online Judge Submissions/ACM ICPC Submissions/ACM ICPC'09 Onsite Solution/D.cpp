#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <int> boy;
int main()
{
    int b, g, i, x, cas = 1;
    while(cin >> b >> g){
        if(b == 0 && g == 0) break;

        for(i = 0; i < b; i++){
            cin >> x;
            boy.pb(x);
        }

        for(i = 0; i < g; i++){
            cin >> x;
        }

        sort(boy.begin(), boy.end());

        printf("Case %d: ", cas++);
        if(b <= g)
            cout << 0 << endl;
        else
            cout << b-g << " " << boy[0] << endl;

        boy.clear();
    }

    return 0;
}
