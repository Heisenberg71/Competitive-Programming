#include <bits/stdc++.h>
#define ll long long
#define LIM 1010
#define nl "\n"
using namespace std;

char str[LIM][LIM];
int grid[LIM][LIM];

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> str[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            grid[i][j] += grid[i][j - 1] + (str[i][j] == '*');

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j] += grid[i - 1][j];
        }
    }

    while(q--){
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << grid[row2][col2] - grid[row1 - 1][col2] - grid[row2][col1 - 1] + grid[row1 - 1][col1 - 1] << nl;
    }

    return 0;
}
