#include <bits/stdc++.h>
#define ll long long
#define inf 1000000009
#define nl "\n"
using namespace std;

int xx[] = {1, -1, -1, 1};
int yy[] = {1, -1, 1, -1};

int n, stRow, stCol, enRow, enCol;
int dist[1505][1505][5];
string grid[1505];

struct abc{
    int row, col, mov;
};

bool valid(abc v)
{
    return (0 <= v.row && v.col < n && !(stRow == v.row && stCol == v.col) && grid[v.row][v.col] == '.' && dist[v.row][v.col][v.mov] == 0);
}

void bfs()
{
    queue <abc> q;
    q.push({stRow, stCol, 0});

    while(!q.empty()){
        abc u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            abc v = {u.row + xx[i], u.col + yy[i], i};
            while(valid(v)){
                q.push(v);
                dist[v.row][v.col][v.mov] = 1 + dist[u.row][u.col][u.mov];
                v.row += xx[i];
                v.col += yy[i];
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> stRow >> stCol;
    cin >> enRow >> enCol;

    stRow--, stCol--, enRow--, enCol--;

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    bfs();

    int ans = inf;
    for(int i = 0; i < 4; i++){
        if(dist[enRow][enCol][i]) ans = min(ans, dist[enRow][enCol][i]);
    }

    if(ans == inf) cout << -1 << nl;
    else cout << ans << nl;

    return 0;
}
