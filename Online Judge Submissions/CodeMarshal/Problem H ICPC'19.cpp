#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf (1<<30)
#define LIM 200005
#define pb push_back
#define ff first
#define ss second
using namespace std;
char grid[105][105];
bool vis[105][105];
ll rr[] = {1, 0, -1, 0};
ll cc[] = {0, 1, 0, -1};
queue <pair<ll,ll> > q;
ll row, col;
bool inside(ll x, ll y)
{
    if(x >= 0 and y >= 0 and x < row-1 and y < col-1)
        return 1;
    return 0;
}
void bfs()
{
    for(ll i = 0; i < col-1; i++){
        if(grid[0][i] == 'D' or grid[0][i] == 'N'){
                vis[0][i] = 1; //cout << i << " ";
                q.push({0,i});
        }
    }
    while(!q.empty()){
        ll topx = q.front().ff, topy = q.front().ss; q.pop();
        //cout << topx << " " << topy << endl;
        for(ll i = 0; i < 4; i++){
            ll one = topx + rr[i];
            ll two = topy + cc[i];
            if(inside(one,two) and !vis[one][two]){
                if(i == 0 and (grid[one][two] == 'D' or grid[one][two] == 'N')){
                    q.push({one,two});
                    vis[one][two] = 1;
                }
                else if(i == 1 and (grid[one][two] == 'R' or grid[one][two] == 'N')){
                    q.push({one,two});
                    vis[one][two] = 1;
                }
                else if(i == 2 and (grid[topx][topy] == 'D' or grid[topx][topy] == 'N')){
                    q.push({one,two});
                    vis[one][two] = 1;
                }
                else if(i == 3 and (grid[topx][topy] == 'R' or grid[topx][topy] == 'N')){
                    q.push({one,two});
                    vis[one][two] = 1;
                }
            }
        }
    }

}
int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t, cas = 1, i, j;
    cin >> t;
    while(t--){
        cin >> row >> col;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                cin >> grid[i][j];
        bfs();
        ll cnt = 0;
        for(i = 0; i < row-1; i++){
            for(j = 0; j < col-1; j++){
                if(vis[i][j]) cnt++;
                vis[i][j] = 0;
                //cout << vis[i][j] << " ";
            }
            //cout << endl;
        }
        printf("Case %lld: %lld\n", cas++, cnt);
        //memset(vis,0,sizeof(vis));
    }




    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/

