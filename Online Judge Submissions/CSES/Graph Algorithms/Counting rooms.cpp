#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define nl '\n'
using namespace std;

int n, m, vis[1003][1003], pre[1003][1003];
char grid[1003][1003];
int rr[] = {1, -1, 0, 0};
int cc[] = {0, 0, 1, -1};

bool inside(int row, int col)
{
    if(0 <= row && row < n && 0 <= col && col < m) return 1;
    return 0;
}

void bfs(int row, int col)
{
    queue <pii> q;
    memset(vis, 127, sizeof vis);

    vis[row][col] = 0;
    q.push({row, col});
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pii v;
            v.ff = u.ff + rr[i];
            v.ss = u.ss + cc[i];
            if(inside(v.ff, v.ss) && grid[v.ff][v.ss] != '#' && vis[u.ff][u.ss] + 1 < vis[v.ff][v.ss]){
                vis[v.ff][v.ss] = 1 + vis[u.ff][u.ss];
                if(i == 0) pre[v.ff][v.ss] = 0;
                else if(i == 1) pre[v.ff][v.ss] = 1;
                else if(i == 2) pre[v.ff][v.ss] = 2;
                else pre[v.ff][v.ss] = 3;
                q.push({v.ff, v.ss});
            }
        }
    }

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++)
//            cout << vis[i][j] << " ";
//        cout << nl;
//    }
}

void print(int val)
{
    if(val == 0) cout << 'U';
    else if(val == 1) cout << 'D';
    else if(val == 2) cout << 'L';
    else cout << 'R';
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B')
                bfs(i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){ //cout << "sf";
            if(grid[i][j] == 'A'){
                if(vis[i][j] <= n*m){
                    cout << "YES" << nl;
                    cout << vis[i][j] << nl;
                    int row = i, col = j;
                    while(vis[row][col]){
                        print(pre[row][col]);
                        //cout << row << " " << col << nl;
                        if(pre[row][col] == 0) row--;
                        else if(pre[row][col] == 1)row++;
                        else if(pre[row][col] == 2) col--;
                        else col++;
                    }
                    cout << nl;
                }
                else cout << "NO" << nl;
                return 0;
            }
        }
    }

    return 0;
}
