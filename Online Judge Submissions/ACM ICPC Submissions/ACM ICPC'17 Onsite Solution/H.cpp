#include <bits/stdc++.h>
using namespace std;
bool table[10005][505];
int main()
{
    int n, x, y;
    while(scanf("%d", &n)){
        if(!n) break;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            table[x][y] = 1;
        }
        int ans = 0, curr = 0;
        //cout << "st: " << endl;
        for(int i = -505; i < 10005; i++){ //cout << i << endl;
            int cnt = 0, cnt2 = 0;
            for(int j = 0; j < 505; j++)
                if(i+j >= 0 && i+j < 10005 && table[i+j][j]) cnt++;
            for(int j = 0; j < 505; j++)
                if(i-j-1 >= 0 && i-j-1 < 10005 && table[i-j-1][j]) cnt2++;
            curr = curr + cnt - cnt2;
            ans = max(ans, curr);
        }
        //cout << "ed" << endl;
        printf("%d\n", ans);
        memset(table, 0, sizeof table);
    }
    return 0;
}
