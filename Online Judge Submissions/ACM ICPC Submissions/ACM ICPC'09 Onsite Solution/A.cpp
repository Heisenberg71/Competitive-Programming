#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, c, cas = 1, q[3005], i, j, prio;
    char ch;

    while(cin >> n >> c){
        if(n == 0 && c == 0) break;

        memset(q, 0, sizeof q);
        for(i = 0; i < min(2005, n); i++)
            q[i] = i+1;

        q[i] = -1;

        printf("Case %d:\n", cas++);

        while(c--){
            cin >> ch;
            if(ch == 'N'){
                int tem = q[0];
                cout << tem << endl;

                for(i = 1; i < 2005; i++){
                    if(q[i] == -1) break;
                    q[i-1] = q[i];
                }

                q[i-1] = tem;
            }
            else{
                cin >> prio;

                for(i = 0; i < 2005; i++)
                    if(q[i] == prio) break;

                if(i == 1005){
                    for(i = 0; i < 2005; i++)
                        if(q[i] == -1) break;

                    for(j = i; j >= 0; j++)
                        q[j+1] = q[j];

                }
                else{
                    for(j = i; j > 0; j--)
                        q[j] = q[j-1];

                }

                q[0] = prio;
            }
        }

    }
    return 0;
}
