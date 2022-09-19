#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct abc{
    int ax, ay, bx, by, cx, cy;
};
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};
int n;

char grid[10][10];

int vis[10][10][10][10][10][10];

abc fun(abc v, int dir)
{
    abc temp = v;

    if(v.ax + xx[dir] >= 0 && v.ax + xx[dir] < n && grid[ v.ax + xx[dir] ][ v.ay + yy[dir] ] != '#') v.ax = v.ax + xx[dir];
    if(v.ay + yy[dir] >= 0 && v.ay + yy[dir] < n && grid[ v.ax + xx[dir] ][ v.ay + yy[dir] ] != '#') v.ay = v.ay + yy[dir];

    if(v.bx + xx[dir] >= 0 && v.bx + xx[dir] < n && grid[ v.bx + xx[dir] ][ v.by + yy[dir] ] != '#') v.bx = v.bx + xx[dir];
    if(v.by + yy[dir] >= 0 && v.by + yy[dir] < n && grid[ v.bx + xx[dir] ][ v.by + yy[dir] ] != '#') v.by = v.by + yy[dir];

    if(v.cx + xx[dir] >= 0 && v.cx + xx[dir] < n && grid[ v.cx + xx[dir] ][ v.cy + yy[dir] ] != '#') v.cx = v.cx + xx[dir];
    if(v.cy + yy[dir] >= 0 && v.cy + yy[dir] < n && grid[ v.cx + xx[dir] ][ v.cy + yy[dir] ] != '#') v.cy = v.cy + yy[dir];

    set <pii> s;
    s.insert({v.ax, v.ay});
    s.insert({v.bx, v.by});
    s.insert({v.cx, v.cy});

    if(s.size() == 3) return v;
    else{
        if(v.ax == v.bx && v.ay == v.by) v.ax = temp.ax, v.ay = temp.ay, v.bx = temp.bx, v.by = temp.by;
        else if(v.ax == v.cx && v.ay == v.cy) v.ax = temp.ax, v.ay = temp.ay, v.cx = temp.cx, v.cy = temp.cy;
        else if(v.bx == v.cx && v.by == v.cy) v.bx = temp.bx, v.by = temp.by, v.cx = temp.cx, v.cy = temp.cy;

        if(v.ax == v.bx && v.ay == v.by) return temp;
        if(v.ax == v.cx && v.ay == v.cy) return temp;
        if(v.bx == v.cx && v.by == v.cy) return temp;

        return v;
    }
}

bool found(abc u)
{
    if(grid[u.ax][u.ay] == 'X' && grid[u.bx][u.by] == 'X' && grid[u.cx][u.cy] == 'X') return 1;
    return 0;
}

void bfs(int ax, int ay, int bx, int by, int cx, int cy)
{
    memset(vis, 127, sizeof vis);
    vis[ax][ay][bx][by][cx][cy] = 0;
    queue <abc> q;
    q.push({ax, ay, bx, by, cx, cy});

    while(!q.empty()){
        abc u = q.front(); q.pop();
        if(found(u)){
//        cout << u.ax << " " << u.ay << endl;
//        cout << u.bx << " " << u.by << endl;
//        cout << u.cx << " " << u.cy << endl << endl;
            printf("%d\n", vis[u.ax][u.ay][u.bx][u.by][u.cx][u.cy]);
            return;
        }
        for(int i = 0; i < 4; i++){
            abc v = fun(u, i);
            if(vis[u.ax][u.ay][u.bx][u.by][u.cx][u.cy] + 1 < vis[v.ax][v.ay][v.bx][v.by][v.cx][v.cy]){
                vis[v.ax][v.ay][v.bx][v.by][v.cx][v.cy] = vis[u.ax][u.ay][u.bx][u.by][u.cx][u.cy] + 1;
                q.push(v);
            }
        }
    }

    printf("trapped\n");
}

int main()
{
    int t, cas = 1;
    int ax, ay, bx, by, cx, cy;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            getchar();
            for(int j = 0; j < n; j++){
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'A') ax = i, ay = j;
                if(grid[i][j] == 'B') bx = i, by = j;
                if(grid[i][j] == 'C') cx = i, cy = j;
            }
        }

        printf("Case %d: ", cas++);
        bfs(ax, ay, bx, by, cx, cy);
    }

    return 0;
}
