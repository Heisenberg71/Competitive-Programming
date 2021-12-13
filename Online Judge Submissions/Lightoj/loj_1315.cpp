#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, dp[505][505];
int r[] = {-1, -2, -3, -2, -1, 1};
int c[] = {-2, 1, -1, -1, -3, -2};

bool inside(int xx, int yy)
{
    if(xx >= 0 && yy >= 0 && xx < 505 && yy < 505) return 1;
    return 0;
}

int f(int row, int col)
{
    if(!inside(row, col)) return 9;
    if(dp[row][col] != -1) return dp[row][col];

    int cnt[15];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < 6; i++)
        cnt[f(row + r[i], col + c[i])] = 1;

    int i;
    for(i = 0; i <= 6; i++)
        if(cnt[i] == 0) break;

    return dp[row][col] = i;
}

int main()
{
    memset(dp, -1, sizeof dp);

//    for(int i = 0; i < 30; i++){
//        for(int j = 0; j < 30; j++)
//            cout << f(i, j) << " ";
//        cout << endl;
//    }

    int t, x, y, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = 0;
        while(n--){
            scanf("%d %d", &x, &y);
            ans ^= f(x, y);
        }
        printf("Case %d: ", cas++);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}

